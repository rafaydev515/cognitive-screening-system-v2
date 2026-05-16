#pragma once

#include <string>
#include <vector>
#include <memory>
#include "ScreeningReport.h"
#include "IExportStrategy.h"

using namespace std;

class ReportExporter {
private:
    string outputDirectory;
    vector<unique_ptr<IExportStrategy>> strategies;

public:
    explicit ReportExporter(const string& outputDirectory);

    void addStrategy(unique_ptr<IExportStrategy> strategy);
    vector<string> exportReports(const ScreeningReport& report) const;
};
