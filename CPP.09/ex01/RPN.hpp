#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#include <exception>

class RPN {
private:
    std::stack<int> _stack;

    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

public:
    RPN(const std::string& expression);
    ~RPN();

    int getResult() const;

    class InvalidExpressionException : public std::exception {
        virtual const char* what() const throw();
    };
};

#endif