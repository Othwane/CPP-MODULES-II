#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Span.hpp"

int main() {
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span sp2 = Span(10000);
        std::vector<int> v;
        for (int i = 0; i < 10000; ++i) {
            v.push_back(i * 2);
        }
        sp2.addRange(v.begin(), v.end());

        std::cout << "Shortest span (10000 numbers): " << sp2.shortestSpan() << std::endl;
        std::cout << "Longest span (10000 numbers): " << sp2.longestSpan() << std::endl;

        Span sp3 = Span(1);
        sp3.addNumber(42);
        try {
            sp3.addNumber(43);
        } catch (const std::exception& e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }

        Span sp4 = Span(1);
        sp4.addNumber(42);
        try {
            sp4.shortestSpan();
        } catch (const std::exception& e) {
            std::cerr << "Expected error: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}