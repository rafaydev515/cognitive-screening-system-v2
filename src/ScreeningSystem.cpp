#include "ScreeningSystem.h"
#include <iostream>
#include <memory>
#include "TextExportStrategy.h"
#include "CsvExportStrategy.h"
#include "JsonExportStrategy.h"

ScreeningSystem::ScreeningSystem(const string& questionFilePath)
    : exporter("reports"), questionFilePath(questionFilePath) {}

void ScreeningSystem::run() {
    questions = loader.loadQuestions(questionFilePath);

    if (questions.empty()) {
        cout << "No questions loaded.\n";
        return;
    }

    askQuestions();
    showAndExportResults();
}

void ScreeningSystem::askQuestions() {
    for (size_t questionIndex = 0; questionIndex < questions.size(); questionIndex++) {
        const Question& question = questions[questionIndex];

        cout << "\n\n\t\tQuestion " << questionIndex + 1 << " of " << questions.size() << '\n';
        cout << "\t\t" << question.getText() << '\n';

        const vector<Option>& options = question.getOptions();
        if (options.empty()) {
            cout << "\t\tWarning: Question has no options. Skipping.\n";
            continue;
        }

        for (size_t i = 0; i < options.size(); i++) {
            cout << "\t\t" << i + 1 << ". " << options[i].getText() << '\n';
        }

        int selectedIndex = input.readBoundedInteger(
            "Select an option (1-" + to_string(options.size()) + "): ",
            1,
            static_cast<int>(options.size()));

        Response response(&options[selectedIndex - 1]);
        scorer.processResponse(response, profile);
    }
}

ScreeningReport ScreeningSystem::buildReport() const {
    map<Trait, int> maxScores = maxScoreCalculator.compute(questions);
    NormalizedProfile normalizedProfile = normalizer.normalize(profile, maxScores);
    ClassificationResult result = classifier.classify(normalizedProfile);
    string interpretation = interpreter.interpret(result);

    return ScreeningReport(profile, normalizedProfile, result, interpretation);
}

void ScreeningSystem::showAndExportResults() {
    cout << "\n\t\t\t===== RESULTS =====\n";

    ScreeningReport report = buildReport();
    presenter.showReport(report);

    int exportChoice = input.readBoundedInteger(
        "\n\tSelect export format (1: Text, 2: CSV, 3: JSON, 4: All): ",
        1,
        4);

    if (exportChoice == 1 || exportChoice == 4) {
        exporter.addStrategy(make_unique<TextExportStrategy>());
    }
    if (exportChoice == 2 || exportChoice == 4) {
        exporter.addStrategy(make_unique<CsvExportStrategy>());
    }
    if (exportChoice == 3 || exportChoice == 4) {
        exporter.addStrategy(make_unique<JsonExportStrategy>());
    }

    vector<string> exportedPaths = exporter.exportReports(report);

    if (exportedPaths.empty()) {
        cout << "\n\t\tReport export failed.\n";
    } else {
        cout << "\n\t\tReports saved to:\n";
        for (const auto& path : exportedPaths) {
            cout << "\t\t - " << path << '\n';
        }
    }
}

