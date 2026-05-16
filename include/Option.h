#pragma once

#include <map>
#include <string>
#include "Trait.h"

using namespace std;

class Option {
private:
    string text;
    map<Trait, int> weights;

public:
    Option(const string& text, const map<Trait, int>& weights);

    const string& getText() const;
    const map<Trait, int>& getWeights() const;
};
