#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include "mycalc.hpp"

int find_sign_position(std::string str) {
    int sign_pos;
    
    sign_pos = str.find('+');
    if (sign_pos != std::string::npos) {
        return sign_pos;
    }
    sign_pos = str.find('-');
    if (sign_pos != std::string::npos) {
        return sign_pos;
    }
    sign_pos = str.find('/');
    if (sign_pos != std::string::npos) {
        return sign_pos;
    }
    sign_pos = str.find('*');
    if (sign_pos != std::string::npos) {
        return sign_pos;
    }

    return std::string::npos;
}

void check_input(std::string arg) {
    std::regex self_regex(R"(^\s*\d*\s*[\+\/\-\*]\s*\d*\s*$)",
            std::regex_constants::ECMAScript | std::regex_constants::icase);
    if (!std::regex_search(arg, self_regex)) {
        throw "u have entered bad input values";
    }

}

std::vector<int> calculate(std::vector<std::string> inputs){
    int first_number;
    int second_number;
    char operation_code;
    std::vector<int> solutions;
    int solution;
    int sign_pos;
 
    for (std::string input : inputs){
        check_input(input);
        sign_pos = find_sign_position(input);
        if (sign_pos == std::string::npos) {
            throw "expression has no operation sign";
        }

        operation_code = input[sign_pos];
        first_number = std::stoi(input.substr(0, sign_pos));
        second_number = std::stoi(input.substr(sign_pos+1, input.size()-sign_pos));

        switch (operation_code)
        {
        case '+':
            solution = first_number + second_number;
            break;
        case '-':
            solution = first_number - second_number;
            break;
            
        case '/':
            if (second_number == 0) {throw "u can't divide by zero!";}
            solution = first_number / second_number;
            break;
        case '*':
            solution = first_number * second_number;
            break;
        default:
            throw "bad operation sign";
        }

        std::cout << "ur solution is: " << solution << "\n";
        solutions.push_back(solution);
    }
    return solutions;
}

std::vector<std::string> readFromFile(std::string fileName){
    // Read from the text file
    std::string line;
    std::vector<std::string> result;
    std::ifstream MyReadFile(fileName);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, line)) {
        result.push_back(line);
    }
    // Close the file
    MyReadFile.close();
    return result;
}

void writeToFile(std::string fileName, std::vector<int> result_value){
// Create and open a text file
  std::ofstream MyFile(fileName);
    for (int input : result_value){
        MyFile << input << "\n";
    }  
  MyFile.close();
}
void writeToFile(std::string fileName, std::string text){
    // Create and open a text file
  std::ofstream MyFile(fileName);
  MyFile << text;
  MyFile.close();
}