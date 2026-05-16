#include "RelaxedClassificationStrategy.h"
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

ClassificationResult RelaxedClassificationStrategy::classify(const NormalizedProfile& profile) const {
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

    int count50 = 0; // Relaxed from 60
    int count30 = 0; // Relaxed from 35
    int count25 = 0; // Relaxed from 29

    for (const auto& score : scores) {
        if (score.second >= 50.0) {
            count50++;
        }
        if (score.second >= 30.0) {
            count30++;
        }
        if (score.second >= 25.0) {
            count25++;
        }
    }

    string profileType;

    if (count50 >= 1) {
        profileType = "Dominant";
    } else if (count30 >= 2) {
        profileType = "Dual";
    } else if (count25 >= 3) {
        profileType = "Triad";
    } else {
        profileType = "Mixed";
    }

    return ClassificationResult(scores[0].first, scores[1].first, profileType);
}
