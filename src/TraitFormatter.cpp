#include "TraitFormatter.h"

string TraitFormatter::toString(Trait trait) {
    switch (trait) {
        case Trait::PatternHunter:
            return "Pattern Hunter";
        case Trait::SocialSmart:
            return "Social Smart";
        case Trait::Explorer:
            return "Explorer";
        case Trait::Stabilizer:
            return "Stabilizer";
        default:
            return "Unknown";
    }
}

