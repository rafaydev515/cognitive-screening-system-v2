#include "MaxScoreCalculator.h"
#include <algorithm>

map<Trait, int> MaxScoreCalculator::compute(const vector<Question>& questions) const {
    map<Trait, int> maxScores;

    for (const Question& question : questions) {
        int maxPatternHunter = 0;
        int maxSocialSmart = 0;
        int maxExplorer = 0;
        int maxStabilizer = 0;

        for (const Option& option : question.getOptions()) {
            const map<Trait, int>& weights = option.getWeights();

            for (const auto& pair : weights) {
                switch (pair.first) {
                    case Trait::PatternHunter:
                        maxPatternHunter = max(maxPatternHunter, pair.second);
                        break;
                    case Trait::SocialSmart:
                        maxSocialSmart = max(maxSocialSmart, pair.second);
                        break;
                    case Trait::Explorer:
                        maxExplorer = max(maxExplorer, pair.second);
                        break;
                    case Trait::Stabilizer:
                        maxStabilizer = max(maxStabilizer, pair.second);
                        break;
                }
            }
        }

        maxScores[Trait::PatternHunter] += maxPatternHunter;
        maxScores[Trait::SocialSmart] += maxSocialSmart;
        maxScores[Trait::Explorer] += maxExplorer;
        maxScores[Trait::Stabilizer] += maxStabilizer;
    }

    return maxScores;
}

