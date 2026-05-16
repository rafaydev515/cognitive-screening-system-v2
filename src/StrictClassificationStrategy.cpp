#include "StrictClassificationStrategy.h"
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

StrictClassificationStrategy::StrictClassificationStrategy()
    : rules(ClassificationRules()) {}

StrictClassificationStrategy::StrictClassificationStrategy(const ClassificationRules& rules)
    : rules(rules) {}

ClassificationResult StrictClassificationStrategy::classify(const NormalizedProfile& profile) const {
    vector<pair<Trait, double>> scores = {
        {Trait::PatternHunter, profile.getPatternHunter()},
        {Trait::SocialSmart, profile.getSocialSmart()},
        {Trait::Explorer, profile.getExplorer()},
        {Trait::Stabilizer, profile.getStabilizer()}
    };

    sort(scores.begin(), scores.end(), [](const auto& first, const auto& second) {
        if (first.second == second.second) {
            return first.first < second.first;
        }
        return first.second > second.second;
    });

    int count60 = 0;
    int count35 = 0;
    int count29 = 0;

    for (const auto& score : scores) {
        if (score.second >= rules.getDominantThreshold()) {
            count60++;
        }
        if (score.second >= rules.getDualThreshold()) {
            count35++;
        }
        if (score.second >= rules.getTriadThreshold()) {
            count29++;
        }
    }

    string profileType;

    if (count60 >= 1) {
        profileType = "Dominant";
    } else if (count35 >= 2) {
        profileType = "Dual";
    } else if (count29 >= 3) {
        profileType = "Triad";
    } else {
        profileType = "Mixed";
    }

    return ClassificationResult(scores[0].first, scores[1].first, profileType);
}
