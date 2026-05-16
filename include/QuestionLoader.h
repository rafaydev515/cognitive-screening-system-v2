#pragma once

#include <string>
#include <vector>
#include "Question.h"

using namespace std;

class QuestionLoader {
public:
    vector<Question> loadQuestions(const string& filename) const;
};
