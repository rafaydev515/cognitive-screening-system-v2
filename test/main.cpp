#include "TestFramework.h"

// Forward declarations
void registerScoringEngineTests(TestRunner& runner);
void registerNormalizationEngineTests(TestRunner& runner);
void registerClassificationEngineTests(TestRunner& runner);

int main() {
    TestRunner runner;

    registerScoringEngineTests(runner);
    registerNormalizationEngineTests(runner);
    registerClassificationEngineTests(runner);

    return runner.run();
}
