#include <iostream>
#include <fstream>
#include <string>
#include "mycalc.hpp"

std::string readFromFile(std::string fileName){
// Read from the text file
    std::string myText;
    std::ifstream MyReadFile(fileName);

// Use a while loop together with the getline() function to read the file line by line
    while (getline(MyReadFile, myText)) {
  
}

// Close the file
MyReadFile.close();
    return myText;
}

void writeToFile(std::string fileName, std::string text){
// Create and open a text file
  std::ofstream MyFile(fileName);
  std::cout << "file opened: " << MyFile.is_open() << "\n";
  MyFile << text;
  MyFile.close();
}

int main() try {
    writeToFile("donyamirea", "1000-7");
    return calculate(readFromFile("donyamirea"));
}

catch (const char* error) {
    std::cout << error;
}