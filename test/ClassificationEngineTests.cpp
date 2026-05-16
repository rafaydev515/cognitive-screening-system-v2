#include "TestFramework.h"
#include "ClassificationEngine.h"
#include "StrictClassificationStrategy.h"
#include "RelaxedClassificationStrategy.h"
#include "NormalizedProfile.h"
#include <memory>

using namespace std;

bool testStrictClassificationDominant() {
    ClassificationEngine engine;
    NormalizedProfile profile(65.0, 20.0, 10.0, 5.0);
    
    ClassificationResult result = engine.classify(profile);
    
    ASSERT_EQ(string("Dominant"), result.getProfileType());
    return true;
}

bool testRelaxedClassificationTriad() {
    ClassificationEngine engine(make_unique<RelaxedClassificationStrategy>());
    NormalizedProfile profile(45.0, 30.0, 26.0, 10.0);
    
    ClassificationResult result = engine.classify(profile);
    
    // In strict, 45, 30, 26, 10 would be: 0 above 60, 0 above 35, 0 above 29 -> Mixed
    // In relaxed (thresholds 50, 30, 25): 0 above 50, 1 above 30, 2 above 25.
    // Wait, relaxed thresholds: count50, count30, count25.
    // profile = 45, 30, 26, 10
    // count50 = 0 (none >= 50)
    // count30 = 2 (45, 30) -> Wait, 45 >= 30 (1), 30 >= 30 (2). So count30 = 2.
    // Result should be Dual since count30 >= 2
    
    ASSERT_EQ(string("Dual"), result.getProfileType());
    return true;
}

void registerClassificationEngineTests(TestRunner& runner) {
    runner.addTest("ClassificationEngine - Strict Dominant", testStrictClassificationDominant);
    runner.addTest("ClassificationEngine - Relaxed Dual", testRelaxedClassificationTriad);
}
