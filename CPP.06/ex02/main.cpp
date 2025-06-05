#include "Base.hpp"
#include <iostream>

int main() {
    Base* base = generate();

    std::cout << "Identified by pointer: ";
    identify(base);

    std::cout << "Identified by reference: ";
    identify(*base);

    delete base;

    // Test with all possible types
    std::cout << "\nTesting all types:\n";
    for (int i = 0; i < 5; i++) {
        Base* test = generate();
        std::cout << "Pointer: ";
        identify(test);
        std::cout << "Reference: ";
        identify(*test);
        std::cout << std::endl;
        delete test;
    }

    return 0;
}