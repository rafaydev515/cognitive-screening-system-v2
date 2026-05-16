# Fixed Programming & Logical Errors

This document details the bugs discovered during the comprehensive stress testing of the Cognitive Screening System and how they were resolved.

## 1. Malformed Format State Leakage (`src/QuestionLoader.cpp`)
**Problem:** The parser printed a warning but failed to clear `currentQuestionText` or `currentOptionText` if it encountered a formatting error (e.g. a line missing the `|` delimiter). Consequently, subsequent valid options or scores were mapped to the *previous* question or option, corrupting the test logic.
**Fix:** Added explicit `.clear()` calls inside the error-handling `else` blocks so the parser cleanly recovers without mixing mismatched entries.

## 2. Non-Deterministic Trait Tie-Breaking (`src/StrictClassificationStrategy.cpp` & `src/RelaxedClassificationStrategy.cpp`)
**Problem:** The `std::sort` lambda solely used `first.second > second.second` to arrange traits by score. When two traits had identical scores (e.g. 50% and 50%), their order was undefined and could swap randomly depending on the compiler's sorting algorithm implementation.
**Fix:** Enhanced the lambda to include a secondary tie-breaker: `if (first.second == second.second) return first.first < second.first;`. This guarantees deterministic behavior based on the underlying `Trait` enum value.

## 3. Infinite Prompt Loop on EOF (`src/ConsoleInput.cpp`)
**Problem:** A standard security/usability edge-case vulnerability. If the input stream is terminated unexpectedly via EOF (e.g., user presses `Ctrl+D` or `Ctrl+Z`), `cin >> value` perpetually evaluates to `false`. Since `cin.ignore` doesn't block on EOF, it created an infinite spam loop of `"Invalid input. Try again: "`.
**Fix:** Added an explicit `if (cin.eof()) { exit(1); }` guard check within the validation loop, allowing the program to cleanly terminate on stream closure.

## 4. Zero Options Infinite Loop Trap (`src/ScreeningSystem.cpp`)
**Problem:** In the extremely rare event a question was successfully parsed but had exactly 0 options, the `askQuestions()` method would call `readBoundedInteger` with `min = 1` and `max = 0`. The validation loop `value < min || value > max` would be impossible to satisfy (e.g., $value < 1 \lor value > 0$), locking the application indefinitely.
**Fix:** Inserted an early-continue safeguard: `if (options.empty()) { continue; }`, ensuring malformed option-less questions are gracefully skipped.
