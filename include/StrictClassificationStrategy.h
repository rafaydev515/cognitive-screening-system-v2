#pragma once

#include "IClassificationStrategy.h"
#include "ClassificationRules.h"

class StrictClassificationStrategy : public IClassificationStrategy {
private:
    ClassificationRules rules;

public:
    StrictClassificationStrategy();
    explicit StrictClassificationStrategy(const ClassificationRules& rules);

    ClassificationResult classify(const NormalizedProfile& profile) const override;
};
