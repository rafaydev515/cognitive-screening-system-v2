#pragma once

#include <string>
#include <vector>
#include "Option.h"

using namespace std;

class Question {
private:
    string text;
    vector<Option> options;

public:
    Question(const string& text, const vector<Option>& options);

    const string& getText() const;
    const vector<Option>& getOptions() const;
};
