#include "Application.h"
#include <iostream>
#include <string>
#include "ScreeningSystem.h"

Application::Application() {}

void Application::run() const {
    cout << "\n\tWelcome to the Cognitive Screening System!\n";
    cout << "\tYou have to answer the given questions to determine your cognitive profile.\n";

    bool keepRunning = true;

    while (keepRunning) {
        int startChoice = input.readBoundedInteger(
            "\tPress 1 to start the screening or 0 to exit: ",
            0,
            1);

        if (startChoice == 1) {
            int testChoice = input.readBoundedInteger(
                "\n\tSelect Test (1: Standard, 2: Advanced): ",
                1,
                2);
            
            string questionFilePath = (testChoice == 1) ? "data/questions.txt" : "data/advanced_questions_v2.txt";

            ScreeningSystem system(questionFilePath);
            system.run();

            int againChoice = input.readBoundedInteger(
                "\n\tPress 1 to run another screening or 0 to exit: ",
                0,
                1);

            keepRunning = (againChoice == 1);
        } else {
            keepRunning = false;
        }
    }

    cout << "Exiting the program. Goodbye!\n";
}
