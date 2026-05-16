#pragma once

#include "ConsoleInput.h"

class Application {
private:
    ConsoleInput input;

public:
    Application();

    void run() const;
};
