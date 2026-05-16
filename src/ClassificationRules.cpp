#include "ClassificationRules.h"

ClassificationRules::ClassificationRules()
    : dominantThreshold(60.0), dualThreshold(35.0), triadThreshold(29.0) {}

ClassificationRules::ClassificationRules(double dominantThreshold, double dualThreshold, double triadThreshold)
    : dominantThreshold(dominantThreshold), dualThreshold(dualThreshold), triadThreshold(triadThreshold) {}

double ClassificationRules::getDominantThreshold() const {
    return dominantThreshold;
}

double ClassificationRules::getDualThreshold() const {
    return dualThreshold;
}

double ClassificationRules::getTriadThreshold() const {
    return triadThreshold;
}

