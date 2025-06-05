#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <stdexcept>

RPN::RPN(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1) {
            char c = token[0];
            if (isdigit(c)) {
                _stack.push(c - '0');
                continue;
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (_stack.size() < 2) {
                    throw InvalidExpressionException();
                }

                int b = _stack.top(); _stack.pop();
                int a = _stack.top(); _stack.pop();

                switch (c) {
                    case '+': _stack.push(a + b); break;
                    case '-': _stack.push(a - b); break;
                    case '*': _stack.push(a * b); break;
                    case '/':
                        if (b == 0) {
                            throw std::runtime_error("Error: division by zero");
                        }
                        _stack.push(a / b);
                        break;
                }
                continue;
            }
        }
        throw InvalidExpressionException();
    }

    if (_stack.size() != 1) {
        throw InvalidExpressionException();
    }
}

RPN::~RPN() {}

int RPN::getResult() const {
    return _stack.top();
}

const char* RPN::InvalidExpressionException::what() const throw() {
    return "Error";
}