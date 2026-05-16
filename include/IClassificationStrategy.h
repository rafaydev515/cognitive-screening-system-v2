#pragma once

#include "ClassificationResult.h"
#include "NormalizedProfile.h"

class IClassificationStrategy {
public:
    virtual ~IClassificationStrategy() = default;
    virtual ClassificationResult classify(const NormalizedProfile& profile) const = 0;
};
