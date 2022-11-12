#include <iostream>
#include <fstream>
#include <string>
#include "mycalc.hpp"

int main() try {
    writeToFile("donyamirea", "1000-7\n1000+1000\n2000-2000"); //создаю массив данных для подсчетов
    std::vector<std::string> inputs = readFromFile("donyamirea");
    std::vector<int> outputs = calculate(inputs); // calculate() = vector<int>
    writeToFile("result.txt", outputs); // запись результата в файл
    return 0;
}

catch (const char* error) {
    std::cout << error;
}