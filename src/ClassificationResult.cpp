#include "ClassificationResult.h"

ClassificationResult::ClassificationResult(Trait dominant, Trait secondary, const string& profileType)
    : dominant(dominant), secondary(secondary), profileType(profileType) {}

Trait ClassificationResult::getDominant() const {
    return dominant;
}

Trait ClassificationResult::getSecondary() const {
    return secondary;
}

const string& ClassificationResult::getProfileType() const {
    return profileType;
}

