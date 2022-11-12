#include <iostream>
#include "mycalc.hpp"

int main() try {
    return calculate("1000+1000");
}

catch (const char* error) {
    std::cout << error;
}