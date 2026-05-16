#pragma once

#include <map>
#include "NormalizedProfile.h"
#include "Trait.h"
#include "TraitProfile.h"

using namespace std;

class NormalizationEngine {
private:
    static double percentage(int score, int maximum);

public:
    NormalizedProfile normalize(const TraitProfile& profile, const map<Trait, int>& maxScores) const;
};
