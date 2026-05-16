#pragma once

#include "Option.h"

class Response {
private:
    const Option* selectedOption;

public:
    explicit Response(const Option* selectedOption);

    const Option* getSelectedOption() const;
};

