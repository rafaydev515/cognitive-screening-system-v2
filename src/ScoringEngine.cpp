#include "ScoringEngine.h"

void ScoringEngine::processResponse(const Response& response, TraitProfile& profile) const {
    const Option* option = response.getSelectedOption();

    if (option == nullptr) {
        return;
    }

    for (const auto& pair : option->getWeights()) {
        profile.addScore(pair.first, pair.second);
    }
}

