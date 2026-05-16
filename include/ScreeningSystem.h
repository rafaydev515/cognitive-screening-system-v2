#pragma once

#include <string>
#include <vector>
#include "ClassificationEngine.h"
#include "ConsoleInput.h"
#include "InterpretationEngine.h"
#include "MaxScoreCalculator.h"
#include "NormalizationEngine.h"
#include "Question.h"
#include "QuestionLoader.h"
#include "ReportExporter.h"
#include "ResultPresenter.h"
#include "ScreeningReport.h"
#include "ScoringEngine.h"
#include "TraitProfile.h"

using namespace std;

class ScreeningSystem {
private:
    QuestionLoader loader;
    ScoringEngine scorer;
    MaxScoreCalculator maxScoreCalculator;
    NormalizationEngine normalizer;
    ClassificationEngine classifier;
    InterpretationEngine interpreter;
    ConsoleInput input;
    ResultPresenter presenter;
    ReportExporter exporter;
    string questionFilePath;
    vector<Question> questions;
    TraitProfile profile;

    void askQuestions();
    ScreeningReport buildReport() const;
    void showAndExportResults();

public:
    explicit ScreeningSystem(const string& questionFilePath);

    void run();
};
