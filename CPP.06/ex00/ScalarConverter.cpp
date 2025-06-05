// ScalarConverter.cpp
#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(const std::string& literal) {
    // Determine type and convert
    char* endPtr = NULL;
    double value = strtod(literal.c_str(), &endPtr);
    bool isChar = (literal.length() == 1 && !isdigit(literal[0]));
    bool isSpecial = (literal == "-inf" || literal == "+inf" || literal == "nan" ||
                     literal == "-inff" || literal == "+inff" || literal == "nanf");

    // Char conversion
    if (isChar) {
        char c = literal[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }

    // Handle special cases
    if (isSpecial) {
        std::string special = literal;
        bool isFloat = (special.back() == 'f');
        if (isFloat) special = special.substr(0, special.length() - 1);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << special << (isFloat ? "f" : "f") << std::endl;
        std::cout << "double: " << special << std::endl;
        return;
    }

    // Check if conversion was successful
    if (endPtr == literal.c_str() || (*endPtr != '\0' && *endPtr != 'f')) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // Char output
    if (value < std::numeric_limits<char>::min() || value > std::numeric_limits<char>::max())
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(value)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;

    // Int output
    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(value) << std::endl;

    // Float and double output
    std::cout << "float: " << std::fixed << std::setprecision(1) 
              << static_cast<float>(value) << "f" << std::endl;
    std::cout << "double: " << std::fixed << std::setprecision(1) 
              << value << std::endl;
}
