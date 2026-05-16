#pragma once

class NormalizedProfile {
private:
    double patternHunter;
    double socialSmart;
    double explorer;
    double stabilizer;

public:
    NormalizedProfile(double patternHunter, double socialSmart, double explorer, double stabilizer);

    double getPatternHunter() const;
    double getSocialSmart() const;
    double getExplorer() const;
    double getStabilizer() const;
};

