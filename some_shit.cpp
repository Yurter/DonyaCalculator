#include <iostream>
#include <string>
#include "some_shit.hpp"

int find_sign_position (std::string str) {
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

int calculate () {
    int first_number;
    int second_number;
    char operation_code;
    int solution;
    int sign_pos;
    
    std::cout << "enter ur expression to be calcucated: ";
    std::string input;
    std::cin >> input;

    sign_pos = find_sign_position(input);
    if (sign_pos == std::string::npos) {
        throw "expression has no operation sign";
    }

    operation_code = input[sign_pos];
    first_number = std::stoi(input.substr(0, sign_pos));
    second_number = std::stoi(input.substr(sign_pos, input.size()-sign_pos));

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

    std::cout << "ur solution is: " << solution;
    return 0;
}