#include "Array.hpp"
#include <iostream>
#include <string>

int main() {
    Array<int> intArr(5);
    for (unsigned int i = 0; i < intArr.size(); i++) {
        intArr[i] = i * 10;
    }

    std::cout << "Int array: ";
    for (unsigned int i = 0; i < intArr.size(); i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    Array<int> intArrCopy(intArr);
    intArrCopy[0] = 100;
    std::cout << "Original after copy modification: " << intArr[0] << std::endl;
    std::cout << "Copy after modification: " << intArrCopy[0] << std::endl;

    Array<int> intArrAssign;
    intArrAssign = intArr;
    intArrAssign[1] = 200;
    std::cout << "Original after assignment modification: " << intArr[1] << std::endl;
    std::cout << "Assignment after modification: " << intArrAssign[1] << std::endl;

    Array<std::string> strArr(3);
    strArr[0] = "Hello";
    strArr[1] = "World";
    strArr[2] = "1337";

    std::cout << "String array: ";
    for (unsigned int i = 0; i < strArr.size(); i++) {
        std::cout << strArr[i] << " ";
    }
    std::cout << std::endl;

    try {
        std::cout << "Trying to access out of bounds: ";
        std::cout << intArr[10] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}