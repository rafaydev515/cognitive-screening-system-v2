#include "TextExportStrategy.h"
#include <ctime>
#include <direct.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "TraitFormatter.h"

using namespace std;

string TextExportStrategy::exportReport(const ScreeningReport& report, const string& outputDirectory) const {
    _mkdir(outputDirectory.c_str());

    time_t currentTime = time(nullptr);
    tm localTime = *localtime(&currentTime);

    stringstream fileName;
    fileName << outputDirectory << "/screening-report-"
             << put_time(&localTime, "%Y%m%d-%H%M%S")
             << ".txt";

    ofstream file(fileName.str());

    if (!file) {
        return "";
    }

    const TraitProfile& raw = report.getRawProfile();
    const NormalizedProfile& normalized = report.getNormalizedProfile();
    const ClassificationResult& classification = report.getClassification();

    file << "Cognitive Screening Report\n";
    file << "==========================\n\n";

    file << "Raw Trait Scores\n";
    file << "Pattern Hunter: " << raw.getPatternHunter() << '\n';
    file << "Social Smart: " << raw.getSocialSmart() << '\n';
    file << "Explorer: " << raw.getExplorer() << '\n';
    file << "Stabilizer: " << raw.getStabilizer() << "\n\n";

    file << fixed << setprecision(2);
    file << "Normalized Scores\n";
    file << "Pattern Hunter: " << normalized.getPatternHunter() << "%\n";
    file << "Social Smart: " << normalized.getSocialSmart() << "%\n";
    file << "Explorer: " << normalized.getExplorer() << "%\n";
    file << "Stabilizer: " << normalized.getStabilizer() << "%\n\n";

    file << "Profile Type: " << classification.getProfileType() << '\n';
    file << "Dominant Trait: " << TraitFormatter::toString(classification.getDominant()) << '\n';
    file << "Secondary Trait: " << TraitFormatter::toString(classification.getSecondary()) << "\n\n";

    file << "Interpretation\n";
    file << report.getInterpretation() << '\n';

    return fileName.str();
}
