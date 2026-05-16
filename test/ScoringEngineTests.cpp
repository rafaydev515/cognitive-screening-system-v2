#include "TestFramework.h"
#include "ScoringEngine.h"
#include "TraitProfile.h"
#include "Response.h"
#include "Option.h"
#include "Question.h"

using namespace std;

bool testScoringEngineIncrementsScores() {
    ScoringEngine engine;
    TraitProfile profile;
    
    map<Trait, int> weights = {
        {Trait::PatternHunter, 5},
        {Trait::SocialSmart, 2},
        {Trait::Explorer, 1},
        {Trait::Stabilizer, 0}
    };
    Option opt("Test Option", weights);
    Response response(&opt);
    
    engine.processResponse(response, profile);
    
    ASSERT_EQ(5, profile.getPatternHunter());
    ASSERT_EQ(2, profile.getSocialSmart());
    ASSERT_EQ(1, profile.getExplorer());
    ASSERT_EQ(0, profile.getStabilizer());
    
    // Add second response
    engine.processResponse(response, profile);
    
    ASSERT_EQ(10, profile.getPatternHunter());
    ASSERT_EQ(4, profile.getSocialSmart());
    ASSERT_EQ(2, profile.getExplorer());
    ASSERT_EQ(0, profile.getStabilizer());

    return true;
}

void registerScoringEngineTests(TestRunner& runner) {
    runner.addTest("ScoringEngine - Increments Scores", testScoringEngineIncrementsScores);
}
