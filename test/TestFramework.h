#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

#define ASSERT_TRUE(condition) \
    do { \
        if (!(condition)) { \
            cerr << "Assertion failed: " << #condition << " at " << __FILE__ << ":" << __LINE__ << endl; \
            return false; \
        } \
    } while (0)

#define ASSERT_FALSE(condition) ASSERT_TRUE(!(condition))

#define ASSERT_EQ(expected, actual) \
    do { \
        if ((expected) != (actual)) { \
            cerr << "Assertion failed: " << #expected << " == " << #actual \
                      << " (Expected: " << (expected) << ", Actual: " << (actual) << ") at " \
                      << __FILE__ << ":" << __LINE__ << endl; \
            return false; \
        } \
    } while (0)

#define ASSERT_NEAR(expected, actual, tolerance) \
    do { \
        if (abs((expected) - (actual)) > (tolerance)) { \
            cerr << "Assertion failed: " << #expected << " is near " << #actual \
                      << " (Expected: " << (expected) << ", Actual: " << (actual) << ") at " \
                      << __FILE__ << ":" << __LINE__ << endl; \
            return false; \
        } \
    } while (0)

struct TestCase {
    string name;
    bool (*func)();
};

class TestRunner {
private:
    vector<TestCase> tests;
    int passed = 0;
    int failed = 0;

public:
    void addTest(const string& name, bool (*func)()) {
        tests.push_back({name, func});
    }

    int run() {
        cout << "Running " << tests.size() << " tests...\n";
        
        for (const auto& test : tests) {
            cout << "Running " << test.name << "... ";
            bool result = false;
            try {
                result = test.func();
            } catch (const exception& e) {
                cerr << "Exception thrown: " << e.what() << endl;
            } catch (...) {
                cerr << "Unknown exception thrown" << endl;
            }

            if (result) {
                cout << "[PASS]\n";
                passed++;
            } else {
                cout << "[FAIL]\n";
                failed++;
            }
        }

        cout << "\nTest Results: " << passed << " passed, " << failed << " failed.\n";
        return failed == 0 ? 0 : 1;
    }
};
