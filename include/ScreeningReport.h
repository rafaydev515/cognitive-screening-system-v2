#pragma once

#include <string>
#include "ClassificationResult.h"
#include "NormalizedProfile.h"
#include "TraitProfile.h"

using namespace std;

class ScreeningReport {
private:
    TraitProfile rawProfile;
    NormalizedProfile normalizedProfile;
    ClassificationResult classification;
    string interpretation;

public:
    ScreeningReport(
        const TraitProfile& rawProfile,
        const NormalizedProfile& normalizedProfile,
        const ClassificationResult& classification,
        const string& interpretation);

    const TraitProfile& getRawProfile() const;
    const NormalizedProfile& getNormalizedProfile() const;
    const ClassificationResult& getClassification() const;
    const string& getInterpretation() const;
};

