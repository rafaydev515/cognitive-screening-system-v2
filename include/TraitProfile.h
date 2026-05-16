#pragma once

#include "Trait.h"

class TraitProfile {
private:
    int patternHunter;
    int socialSmart;
    int explorer;
    int stabilizer;

public:
    TraitProfile();

    void addScore(Trait trait, int value);

    int getPatternHunter() const;
    int getSocialSmart() const;
    int getExplorer() const;
    int getStabilizer() const;
};

