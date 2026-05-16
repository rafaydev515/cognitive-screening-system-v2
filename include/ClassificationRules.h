#pragma once

class ClassificationRules {
private:
    double dominantThreshold;
    double dualThreshold;
    double triadThreshold;

public:
    ClassificationRules();
    ClassificationRules(double dominantThreshold, double dualThreshold, double triadThreshold);

    double getDominantThreshold() const;
    double getDualThreshold() const;
    double getTriadThreshold() const;
};

