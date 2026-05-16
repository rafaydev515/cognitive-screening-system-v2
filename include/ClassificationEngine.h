#pragma once

#include <memory>
#include "IClassificationStrategy.h"
#include "ClassificationResult.h"
#include "NormalizedProfile.h"

using namespace std;

class ClassificationEngine {
private:
    unique_ptr<IClassificationStrategy> strategy;

public:
    ClassificationEngine(); // Defaults to Strict
    explicit ClassificationEngine(unique_ptr<IClassificationStrategy> strat);

    ClassificationResult classify(const NormalizedProfile& profile) const;
    void setStrategy(unique_ptr<IClassificationStrategy> strat);
};
