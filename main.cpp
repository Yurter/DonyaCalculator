#include <iostream>
#include "some_shit.hpp"

int main() try {
    return calculate();
}

catch (const char* error) {
    std::cout << error;
}