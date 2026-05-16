#include "Response.h"

Response::Response(const Option* selectedOption)
    : selectedOption(selectedOption) {}

const Option* Response::getSelectedOption() const {
    return selectedOption;
}

