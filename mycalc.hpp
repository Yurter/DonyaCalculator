#pragma once
#include <string>
#include <vector>

std::vector<int> calculate(std::vector<std::string> inputs);
void writeToFile(std::string fileName, std::vector<int> result_value);
void writeToFile(std::string fileName, std::string text);
std::vector<std::string> readFromFile(std::string fileName);