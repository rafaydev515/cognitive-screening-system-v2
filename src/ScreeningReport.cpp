#include "ScreeningReport.h"

ScreeningReport::ScreeningReport(
    const TraitProfile& rawProfile,
    const NormalizedProfile& normalizedProfile,
    const ClassificationResult& classification,
    const string& interpretation)
    : rawProfile(rawProfile),
      normalizedProfile(normalizedProfile),
      classification(classification),
      interpretation(interpretation) {}

const TraitProfile& ScreeningReport::getRawProfile() const {
    return rawProfile;
}

const NormalizedProfile& ScreeningReport::getNormalizedProfile() const {
    return normalizedProfile;
}

const ClassificationResult& ScreeningReport::getClassification() const {
    return classification;
}

const string& ScreeningReport::getInterpretation() const {
    return interpretation;
}

