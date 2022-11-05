#include <iostream>
#include "some_shit.hpp"

int read_number_from_input() {
    int number;
    std::cin >> number;
    if(!std::cin){
    //if(std::cin.fail()){
        throw "u should enter only numbers";
    }
    return number;
}

int calculate () {
    int first_number;
    int second_number;
    char operation_code;
    int solution;

    std::cout << "enter ur first number: ";
    first_number = read_number_from_input();
    std::cout << "enter ur second number: ";
    second_number = read_number_from_input();
    //std::cout << "Choose operation:\n\t1 - addition;\n\t2 - subtraction;\n\t3 - division;\n\t4 - multiplication.\n";
     
    std::cout << "Choose operation:\n"
        "1 - addition;\n"
        "2 - subtraction;\n"
        "3 - division;\n" 
        "4 - multiplication.\n";
    std::cout << "ur op. code is: ";
    std::cin >> operation_code;

    switch (operation_code)
    {
    case '1':
        solution = first_number + second_number;
        break;
    case '2':
        solution = first_number - second_number;
        break;
        
    case '3':
        if (second_number == 0) {throw "u can't divide by zero!";}
        solution = first_number / second_number;
        break;
    default:
        solution = first_number * second_number;
        break;
    }

    std::cout << "ur solution is: " << solution;
    return 0;
}