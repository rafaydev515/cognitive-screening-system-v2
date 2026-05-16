#include "CsvExportStrategy.h"
#include <ctime>
#include <direct.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "TraitFormatter.h"

using namespace std;

string CsvExportStrategy::exportReport(const ScreeningReport& report, const string& outputDirectory) const {
    _mkdir(outputDirectory.c_str());

    time_t currentTime = time(nullptr);
    tm localTime = *localtime(&currentTime);

    stringstream fileName;
    fileName << outputDirectory << "/screening-report-"
             << put_time(&localTime, "%Y%m%d-%H%M%S")
             << ".csv";

    ofstream file(fileName.str());

    if (!file) {
        return "";
    }

    const TraitProfile& raw = report.getRawProfile();
    const NormalizedProfile& normalized = report.getNormalizedProfile();
    const ClassificationResult& classification = report.getClassification();

    file << "Trait,Raw Score,Normalized Score (%)\n";
    file << fixed << setprecision(2);
    
    file << "Pattern Hunter," << raw.getPatternHunter() << "," << normalized.getPatternHunter() << "\n";
    file << "Social Smart," << raw.getSocialSmart() << "," << normalized.getSocialSmart() << "\n";
    file << "Explorer," << raw.getExplorer() << "," << normalized.getExplorer() << "\n";
    file << "Stabilizer," << raw.getStabilizer() << "," << normalized.getStabilizer() << "\n";
    
    file << "\n";
    file << "Profile Type," << classification.getProfileType() << "\n";
    file << "Dominant Trait," << TraitFormatter::toString(classification.getDominant()) << "\n";
    file << "Secondary Trait," << TraitFormatter::toString(classification.getSecondary()) << "\n";

    return fileName.str();
}
