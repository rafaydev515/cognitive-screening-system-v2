#include "ConsoleInput.h"
#include <iostream>
#include <limits>
#include <cstdlib>

int ConsoleInput::readBoundedInteger(const string& prompt, int minimum, int maximum) const {
    int value = 0;
    cout << prompt;

    while (!(cin >> value) || value < minimum || value > maximum) {
        if (cin.eof()) {
            cout << "\nInput stream closed. Exiting.\n";
            exit(1);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Try again: ";
    }

    return value;
}

