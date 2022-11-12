#include <iostream>
#include <fstream>
#include <string>
#include "mycalc.hpp"

int main() try {
    writeToFile("donyamirea", "1000-7");
    int tmp = calculate(readFromFile("donyamirea"));
    std::string s = std::to_string(tmp);
    writeToFile("result.txt", s);
    return 0;
}

catch (const char* error) {
    std::cout << error;
}