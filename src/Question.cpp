#include "Question.h"

Question::Question(const string& text, const vector<Option>& options)
    : text(text), options(options) {}

const string& Question::getText() const {
    return text;
}

const vector<Option>& Question::getOptions() const {
    return options;
}

