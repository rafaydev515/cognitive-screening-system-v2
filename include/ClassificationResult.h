#pragma once

#include <string>
#include "Trait.h"

using namespace std;

class ClassificationResult {
private:
    Trait dominant;
    Trait secondary;
    string profileType;

public:
    ClassificationResult(Trait dominant, Trait secondary, const string& profileType);

    Trait getDominant() const;
    Trait getSecondary() const;
    const string& getProfileType() const;
};
