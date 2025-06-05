#include "iter.hpp"
#include <iostream>

// Test functions
template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

void increment(int &n) {
    n++;
}

void square(const int &n) {
    std::cout << n * n << " ";
}

int main() {
    // Test with int array
    int intArr[] = {1, 2, 3, 4, 5};
    size_t intLength = sizeof(intArr) / sizeof(intArr[0]);

    std::cout << "Original int array: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << std::endl;

    iter(intArr, intLength, increment);
    std::cout << "After increment: ";
    iter(intArr, intLength, printElement<int>);
    std::cout << std::endl;

    std::cout << "Squares (const): ";
    iter(intArr, intLength, square);
    std::cout << std::endl;

    std::string strArr[] = {"Hello", "World", "1337", "Tètouan"};
    size_t strLength = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "String array: ";
    iter(strArr, strLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}