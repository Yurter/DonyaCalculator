#include <iostream>
#include "some_shit.hpp"

int read_number_from_input() {
    int number;
    std::cin >> number;

    if(!std::cin){
            throw "u should enter only numbers";
    }
    return number;
}


int calculate () {
    int first_number;
    int second_number;
    char operation_code;
    int solution;

    std::cout << "enter ur expression to be calcucated: ";
    std::string input;
    std::cin >> input;

    if (input.size() != 3) {
        throw "bad format";
    }

    first_number = input[0] - '0';
    operation_code = input[1];
    second_number = input[2] - '0';

    if (first_number < 0 || first_number > 9){
        throw "bad first number";
    }

    
    if (second_number < 0 || second_number > 9){
        throw "bad second number";
    }



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