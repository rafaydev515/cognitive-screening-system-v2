#include "ReportExporter.h"

ReportExporter::ReportExporter(const string& outputDirectory)
    : outputDirectory(outputDirectory) {}

void ReportExporter::addStrategy(unique_ptr<IExportStrategy> strategy) {
    if (strategy) {
        strategies.push_back(move(strategy));
    }
}

vector<string> ReportExporter::exportReports(const ScreeningReport& report) const {
    vector<string> filePaths;
    for (const auto& strategy : strategies) {
        string path = strategy->exportReport(report, outputDirectory);
        if (!path.empty()) {
            filePaths.push_back(path);
        }
    }
    return filePaths;
}
