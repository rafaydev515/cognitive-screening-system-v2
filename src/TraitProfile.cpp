#include "TraitProfile.h"

TraitProfile::TraitProfile()
    : patternHunter(0), socialSmart(0), explorer(0), stabilizer(0) {}

void TraitProfile::addScore(Trait trait, int value) {
    switch (trait) {
        case Trait::PatternHunter:
            patternHunter += value;
            break;
        case Trait::SocialSmart:
            socialSmart += value;
            break;
        case Trait::Explorer:
            explorer += value;
            break;
        case Trait::Stabilizer:
            stabilizer += value;
            break;
    }
}

int TraitProfile::getPatternHunter() const {
    return patternHunter;
}

int TraitProfile::getSocialSmart() const {
    return socialSmart;
}

int TraitProfile::getExplorer() const {
    return explorer;
}

int TraitProfile::getStabilizer() const {
    return stabilizer;
}

