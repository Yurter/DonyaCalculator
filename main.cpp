#include <iostream>
#include <typeinfo>
#include <math.h>

int main() {
    int first_number;
    int second_number;
    char operation_code;
    int solution;
// полетела школа..
    std::cout << "enter ur first number: ";
    std::cin >> first_number;
    std::cout << "enter ur second number: ";
    std::cin >> second_number;
    std::cout << "Choose operation:\n\t1 - addition;\n\t2 - subtraction;\n\t3 - division;\n\t4 - multiplication.\n";
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
        solution = first_number / second_number;
        break;
    default:
        solution = first_number * second_number;
        break;
    }

    std::cout << "ur solution is: " << solution;

    return 0;
}
