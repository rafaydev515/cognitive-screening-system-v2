#pragma once

#include "IClassificationStrategy.h"

class RelaxedClassificationStrategy : public IClassificationStrategy {
public:
    ClassificationResult classify(const NormalizedProfile& profile) const override;
};
