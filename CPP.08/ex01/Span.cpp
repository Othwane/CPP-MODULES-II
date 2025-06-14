#include "Span.hpp"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::Span(const Span& other) : _maxSize(other._maxSize), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _maxSize = other._maxSize;
        _numbers = other._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int num) {
    if (_numbers.size() >= _maxSize) {
        throw FullException();
    }
    _numbers.push_back(num);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }

    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}

unsigned int Span::size() const {
    return _numbers.size();
}

unsigned int Span::capacity() const {
    return _maxSize;
}

const char* Span::FullException::what() const throw() {
    return "Span is full, cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "Not enough numbers to calculate span";
}