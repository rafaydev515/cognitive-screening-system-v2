#pragma once

#include "Response.h"
#include "TraitProfile.h"

class ScoringEngine {
public:
    void processResponse(const Response& response, TraitProfile& profile) const;
};

