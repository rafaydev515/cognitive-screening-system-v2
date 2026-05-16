#include "JsonExportStrategy.h"
#include <ctime>
#include <direct.h>
#include <fstream>
#include <iomanip>
#include <sstream>
#include "TraitFormatter.h"

using namespace std;

// Helper to escape strings for JSON
string escapeJsonString(const string& input) {
    ostringstream ss;
    for (char c : input) {
        switch (c) {
            case '"': ss << "\\\""; break;
            case '\\': ss << "\\\\"; break;
            case '\b': ss << "\\b"; break;
            case '\f': ss << "\\f"; break;
            case '\n': ss << "\\n"; break;
            case '\r': ss << "\\r"; break;
            case '\t': ss << "\\t"; break;
            default:
                if ('\x00' <= c && c <= '\x1f') {
                    ss << "\\u" << hex << setw(4) << setfill('0') << static_cast<int>(c);
                } else {
                    ss << c;
                }
        }
    }
    return ss.str();
}

string JsonExportStrategy::exportReport(const ScreeningReport& report, const string& outputDirectory) const {
    _mkdir(outputDirectory.c_str());

    time_t currentTime = time(nullptr);
    tm localTime = *localtime(&currentTime);

    stringstream fileName;
    fileName << outputDirectory << "/screening-report-"
             << put_time(&localTime, "%Y%m%d-%H%M%S")
             << ".json";

    ofstream file(fileName.str());

    if (!file) {
        return "";
    }

    const TraitProfile& raw = report.getRawProfile();
    const NormalizedProfile& normalized = report.getNormalizedProfile();
    const ClassificationResult& classification = report.getClassification();

    file << fixed << setprecision(2);
    file << "{\n";
    
    file << "  \"raw_scores\": {\n";
    file << "    \"pattern_hunter\": " << raw.getPatternHunter() << ",\n";
    file << "    \"social_smart\": " << raw.getSocialSmart() << ",\n";
    file << "    \"explorer\": " << raw.getExplorer() << ",\n";
    file << "    \"stabilizer\": " << raw.getStabilizer() << "\n";
    file << "  },\n";

    file << "  \"normalized_scores\": {\n";
    file << "    \"pattern_hunter\": " << normalized.getPatternHunter() << ",\n";
    file << "    \"social_smart\": " << normalized.getSocialSmart() << ",\n";
    file << "    \"explorer\": " << normalized.getExplorer() << ",\n";
    file << "    \"stabilizer\": " << normalized.getStabilizer() << "\n";
    file << "  },\n";
    
    file << "  \"classification\": {\n";
    file << "    \"profile_type\": \"" << escapeJsonString(classification.getProfileType()) << "\",\n";
    file << "    \"dominant_trait\": \"" << escapeJsonString(TraitFormatter::toString(classification.getDominant())) << "\",\n";
    file << "    \"secondary_trait\": \"" << escapeJsonString(TraitFormatter::toString(classification.getSecondary())) << "\"\n";
    file << "  },\n";
    
    file << "  \"interpretation\": \"" << escapeJsonString(report.getInterpretation()) << "\"\n";

    file << "}\n";

    return fileName.str();
}
