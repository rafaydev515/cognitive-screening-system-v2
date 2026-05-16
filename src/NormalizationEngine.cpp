#include "NormalizationEngine.h"

double NormalizationEngine::percentage(int score, int maximum) {
    if (maximum == 0) {
        return 0.0;
    }

    return (score / static_cast<double>(maximum)) * 100.0;
}

NormalizedProfile NormalizationEngine::normalize(
    const TraitProfile& profile,
    const map<Trait, int>& maxScores) const {
    return NormalizedProfile(
        percentage(profile.getPatternHunter(), maxScores.at(Trait::PatternHunter)),
        percentage(profile.getSocialSmart(), maxScores.at(Trait::SocialSmart)),
        percentage(profile.getExplorer(), maxScores.at(Trait::Explorer)),
        percentage(profile.getStabilizer(), maxScores.at(Trait::Stabilizer)));
}
