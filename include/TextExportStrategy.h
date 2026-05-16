#pragma once

#include "IExportStrategy.h"

using namespace std;

class TextExportStrategy : public IExportStrategy {
public:
    string exportReport(const ScreeningReport& report, const string& outputDirectory) const override;
};
