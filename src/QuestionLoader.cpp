#include "QuestionLoader.h"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

namespace {
bool isValidScoreLine(const string& patternHunter, const string& socialSmart, const string& explorer, const string& stabilizer) {
    return !patternHunter.empty()
        && !socialSmart.empty()
        && !explorer.empty()
        && !stabilizer.empty();
}
}

vector<Question> QuestionLoader::loadQuestions(const string& filename) const {
    ifstream file(filename);
    string line;
    string currentQuestionText;
    string currentOptionText;
    vector<Option> currentOptions;
    vector<Question> questions;
    int lineNumber = 0;

    if (!file) {
        cout << "Error: File not found\n";
        return questions;
    }

    while (getline(file, line)) {
        lineNumber++;

        if (line.empty() || line[0] == '#') {
            continue;
        }

        if (line.rfind("[Q]", 0) == 0) {
            if (!currentQuestionText.empty()) {
                if (currentOptions.empty()) {
                    cout << "Warning: skipped question with no options before line " << lineNumber << ".\n";
                } else {
                questions.push_back(Question(currentQuestionText, currentOptions));
                }
                currentOptions.clear();
            }

            string content = line.substr(4);
            size_t position = content.find('|');

            if (position != string::npos) {
                currentQuestionText = content.substr(position + 1);
            } else {
                cout << "Warning: invalid question format at line " << lineNumber << ".\n";
                currentQuestionText.clear();
            }
        } else if (line.rfind("[OPT]", 0) == 0) {
            string content = line.substr(6);
            size_t position = content.find('|');

            if (position != string::npos) {
                currentOptionText = content.substr(position + 1);
            } else {
                cout << "Warning: invalid option format at line " << lineNumber << ".\n";
                currentOptionText.clear();
            }
        } else if (line.rfind("[SCORE]", 0) == 0) {
            if (currentOptionText.empty()) {
                cout << "Warning: score without option at line " << lineNumber << ".\n";
                continue;
            }

            string content = line.substr(8);
            stringstream scores(content);
            string patternHunter;
            string socialSmart;
            string explorer;
            string stabilizer;

            getline(scores, patternHunter, '|');
            getline(scores, socialSmart, '|');
            getline(scores, explorer, '|');
            getline(scores, stabilizer, '|');

            if (!isValidScoreLine(patternHunter, socialSmart, explorer, stabilizer)) {
                cout << "Warning: invalid score format at line " << lineNumber << ".\n";
                currentOptionText.clear();
                continue;
            }

            map<Trait, int> weights;
            try {
                weights[Trait::PatternHunter] = stoi(patternHunter);
                weights[Trait::SocialSmart] = stoi(socialSmart);
                weights[Trait::Explorer] = stoi(explorer);
                weights[Trait::Stabilizer] = stoi(stabilizer);
            } catch (...) {
                cout << "Warning: non-numeric score at line " << lineNumber << ".\n";
                currentOptionText.clear();
                continue;
            }

            currentOptions.push_back(Option(currentOptionText, weights));
            currentOptionText.clear();
        }
    }

    if (!currentQuestionText.empty()) {
        if (currentOptions.empty()) {
            cout << "Warning: skipped final question because it has no options.\n";
        } else {
            questions.push_back(Question(currentQuestionText, currentOptions));
        }
    }

    return questions;
}
