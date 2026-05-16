#pragma once

#include <string>
#include "ScreeningReport.h"

using namespace std;

class IExportStrategy {
public:
    virtual ~IExportStrategy() = default;
    
    // Returns the file path of the exported report
    virtual string exportReport(const ScreeningReport& report, const string& outputDirectory) const = 0;
};
