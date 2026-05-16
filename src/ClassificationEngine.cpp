#include "ClassificationEngine.h"
#include "StrictClassificationStrategy.h"

using namespace std;

ClassificationEngine::ClassificationEngine()
    : strategy(make_unique<StrictClassificationStrategy>()) {}

ClassificationEngine::ClassificationEngine(unique_ptr<IClassificationStrategy> strat)
    : strategy(move(strat)) {}

ClassificationResult ClassificationEngine::classify(const NormalizedProfile& profile) const {
    if (strategy) {
        return strategy->classify(profile);
    }
    // Fallback if no strategy is set
    return ClassificationResult(Trait::PatternHunter, Trait::SocialSmart, "Unknown");
}

void ClassificationEngine::setStrategy(unique_ptr<IClassificationStrategy> strat) {
    strategy = move(strat);
}
