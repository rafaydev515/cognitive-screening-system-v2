#include "NormalizedProfile.h"

NormalizedProfile::NormalizedProfile(double patternHunter, double socialSmart, double explorer, double stabilizer)
    : patternHunter(patternHunter), socialSmart(socialSmart), explorer(explorer), stabilizer(stabilizer) {}

double NormalizedProfile::getPatternHunter() const {
    return patternHunter;
}

double NormalizedProfile::getSocialSmart() const {
    return socialSmart;
}

double NormalizedProfile::getExplorer() const {
    return explorer;
}

double NormalizedProfile::getStabilizer() const {
    return stabilizer;
}

