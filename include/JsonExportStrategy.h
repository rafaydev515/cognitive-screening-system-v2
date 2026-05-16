#pragma once

#include "IExportStrategy.h"

using namespace std;

class JsonExportStrategy : public IExportStrategy {
public:
    string exportReport(const ScreeningReport& report, const string& outputDirectory) const override;
};
