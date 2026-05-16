#pragma once

#include <string>
using namespace std;

class ConsoleInput {
public:
    int readBoundedInteger(const string& prompt, int minimum, int maximum) const;
};

