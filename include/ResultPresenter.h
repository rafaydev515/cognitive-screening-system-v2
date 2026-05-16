#pragma once

#include "ClassificationResult.h"
#include "NormalizedProfile.h"
#include "ScreeningReport.h"
#include "TraitProfile.h"

using namespace std;

class ResultPresenter {
private:
    string buildTraitBar(double percentage) const;

public:
    void showReport(const ScreeningReport& report) const;
    void showRawScores(const TraitProfile& profile) const;
    void showNormalizedScores(const NormalizedProfile& profile) const;
    void showClassification(const ClassificationResult& result) const;
    void showInterpretation(const string& interpretation) const;
};
