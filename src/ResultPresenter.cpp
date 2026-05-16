#include "ResultPresenter.h"
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include "TraitFormatter.h"

string ResultPresenter::buildTraitBar(double percentage) const {
    const int width = 20;
    int filled = static_cast<int>(round((percentage / 100.0) * width));
    filled = max(0, min(width, filled));

    return "[" + string(filled, '#') + string(width - filled, '.') + "]";
}

void ResultPresenter::showReport(const ScreeningReport& report) const {
    showRawScores(report.getRawProfile());
    showNormalizedScores(report.getNormalizedProfile());
    showClassification(report.getClassification());
    showInterpretation(report.getInterpretation());
}

void ResultPresenter::showRawScores(const TraitProfile& profile) const {
    cout << "\n\t\tRaw Trait Scores:\n";
    cout << "\t\t\tPattern Hunter: " << profile.getPatternHunter() << '\n';
    cout << "\t\t\tSocial Smart: " << profile.getSocialSmart() << '\n';
    cout << "\t\t\tExplorer: " << profile.getExplorer() << '\n';
    cout << "\t\t\tStabilizer: " << profile.getStabilizer() << '\n';
}

void ResultPresenter::showNormalizedScores(const NormalizedProfile& profile) const {
    cout << "\n\t\tNormalized Scores:\n";
    cout << fixed << setprecision(2);
    cout << "\t\t\tPattern Hunter: " << buildTraitBar(profile.getPatternHunter()) << " " << profile.getPatternHunter() << "%\n";
    cout << "\t\t\tSocial Smart:    " << buildTraitBar(profile.getSocialSmart()) << " " << profile.getSocialSmart() << "%\n";
    cout << "\t\t\tExplorer:        " << buildTraitBar(profile.getExplorer()) << " " << profile.getExplorer() << "%\n";
    cout << "\t\t\tStabilizer:      " << buildTraitBar(profile.getStabilizer()) << " " << profile.getStabilizer() << "%\n";
}

void ResultPresenter::showClassification(const ClassificationResult& result) const {
    cout << "\n\t\tProfile Type: " << result.getProfileType() << '\n';
    cout << "\t\t\tDominant Trait: " << TraitFormatter::toString(result.getDominant()) << '\n';
    cout << "\t\t\tSecondary Trait: " << TraitFormatter::toString(result.getSecondary()) << '\n';
}

void ResultPresenter::showInterpretation(const string& interpretation) const {
    cout << "\n\t\tInterpretation:\n";
    cout << "\t\t\t" << interpretation << '\n';
}
