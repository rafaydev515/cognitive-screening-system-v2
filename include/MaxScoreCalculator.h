#pragma once

#include <map>
#include <vector>
#include "Question.h"
#include "Trait.h"

using namespace std;

class MaxScoreCalculator {
public:
    map<Trait, int> compute(const vector<Question>& questions) const;
};

