#pragma once

#include <string>
#include "ClassificationResult.h"

using namespace std;

class InterpretationEngine {
public:
    string interpret(const ClassificationResult& result) const;
};

