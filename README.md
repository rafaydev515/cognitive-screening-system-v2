
# Cognitive Screening System (C++ OOP) - Version 2

## Overview

This project is a console-based cognitive screening system designed to evaluate user traits using weighted question-response mapping.

The project demonstrates practical Object-Oriented Programming through separated models, scoring services, classification logic, presentation, and report generation.

## Core Features

* Multi-trait evaluation:
  * Pattern Hunter
  * Social Smart
  * Explorer
  * Stabilizer
* Weighted scoring per question
* Score normalization
* Trait classification
* Interpretation engine
* Question progress display
* Visual trait bars
* Automatic text report export
* Repeat screening option
* Basic question-file validation
* CMake build support

## System Flow

Questions -> Responses -> Scoring -> Normalization -> Classification -> Interpretation -> Report -> Output/Export

## OOP Concepts Applied

* Encapsulation
* Separation of Concerns
* Single Responsibility Principle
* Modular design
* Report generation
* Configurable classification rules

## Project Status

This is Version 2 of the system.

### Current Limitations

* Classification logic is still rule-based
* Limited configurability
* No automated test suite yet

## Future Improvements

* Introduce Strategy Pattern for classification
* Add CSV/JSON export
* Add automated tests
* Add admin question editor
* Add comparison between two users

## How to Run

Compile:

```bash
g++ src/*.cpp -Iinclude -std=c++14 -o app
```

Compile on Windows PowerShell:

```powershell
g++ src\*.cpp -Iinclude -std=c++14 -o app.exe
```

Compile with CMake:

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./app
```

Run on Windows PowerShell:

```powershell
.\app.exe
```

## Output

Text reports are saved automatically in the `reports/` directory.

## Author

Muhammad Rafay
