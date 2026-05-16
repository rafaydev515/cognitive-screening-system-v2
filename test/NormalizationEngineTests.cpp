#include "TestFramework.h"
#include "NormalizationEngine.h"
#include "TraitProfile.h"
#include "NormalizedProfile.h"
#include <map>

using namespace std;

bool testNormalizationEngineHandlesNormalCase() {
    NormalizationEngine engine;
    
    TraitProfile profile;
    profile.addScore(Trait::PatternHunter, 50);
    profile.addScore(Trait::SocialSmart, 30);
    profile.addScore(Trait::Explorer, 20);
    profile.addScore(Trait::Stabilizer, 10);
    
    map<Trait, int> maxScores = {
        {Trait::PatternHunter, 100},
        {Trait::SocialSmart, 100},
        {Trait::Explorer, 50},
        {Trait::Stabilizer, 10}
    };
    
    NormalizedProfile normalized = engine.normalize(profile, maxScores);
    
    ASSERT_NEAR(50.0, normalized.getPatternHunter(), 0.01);
    ASSERT_NEAR(30.0, normalized.getSocialSmart(), 0.01);
    ASSERT_NEAR(40.0, normalized.getExplorer(), 0.01);
    ASSERT_NEAR(100.0, normalized.getStabilizer(), 0.01);
    
    return true;
}

bool testNormalizationEngineHandlesZeroMaxScore() {
    NormalizationEngine engine;
    
    TraitProfile profile;
    profile.addScore(Trait::PatternHunter, 50);
    
    map<Trait, int> maxScores = {
        {Trait::PatternHunter, 0}, // Zero max score to test division by zero guard
        {Trait::SocialSmart, 0},
        {Trait::Explorer, 0},
        {Trait::Stabilizer, 0}
    };
    
    NormalizedProfile normalized = engine.normalize(profile, maxScores);
    
    ASSERT_NEAR(0.0, normalized.getPatternHunter(), 0.01);
    
    return true;
}

void registerNormalizationEngineTests(TestRunner& runner) {
    runner.addTest("NormalizationEngine - Normal Case", testNormalizationEngineHandlesNormalCase);
    runner.addTest("NormalizationEngine - Zero Max Score", testNormalizationEngineHandlesZeroMaxScore);
}
