#include "Option.h"

Option::Option(const string& text, const map<Trait, int>& weights)
    : text(text), weights(weights) {}

const string& Option::getText() const {
    return text;
}

const map<Trait, int>& Option::getWeights() const {
    return weights;
}

