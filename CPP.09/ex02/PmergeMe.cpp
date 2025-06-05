#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe(int argc, char** argv) {
    if (argc < 2) {
        throw std::runtime_error("Error: no input sequence provided");
    }

    for (int i = 1; i < argc; ++i) {
        std::string numStr(argv[i]);
        std::istringstream iss(numStr);
        int num;

        if (!(iss >> num) || !iss.eof()) {
            throw std::runtime_error("Error: invalid number format");
        }
        if (num < 0) {
            throw std::runtime_error("Error: negative number");
        }

        _vec.push_back(num);
        _deq.push_back(num);
    }
}

PmergeMe::~PmergeMe() {}

template <typename Container>
void PmergeMe::insertionSort(Container& c) {
    for (size_t i = 1; i < c.size(); ++i) {
        int key = c[i];
        size_t j = i;
        while (j > 0 && c[j - 1] > key) {
            c[j] = c[j - 1];
            --j;
        }
        c[j] = key;
    }
}

template <typename Container>
void PmergeMe::merge(Container& c, Container& left, Container& right) {
    size_t i = 0, j = 0, k = 0;
    size_t leftSize = left.size();
    size_t rightSize = right.size();

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            c[k++] = left[i++];
        } else {
            c[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        c[k++] = left[i++];
    }

    while (j < rightSize) {
        c[k++] = right[j++];
    }
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& c) {
    if (c.size() <= 10) {
        insertionSort(c);
        return;
    }

    size_t mid = c.size() / 2;
    Container left(c.begin(), c.begin() + mid);
    Container right(c.begin() + mid, c.end());

    mergeInsertSort(left);
    mergeInsertSort(right);
    merge(c, left, right);
}

void PmergeMe::sortAndDisplay() {
    // Display before
    std::cout << "Before: ";
    for (size_t i = 0; i < _vec.size() && i < 5; ++i) {
        std::cout << _vec[i] << " ";
    }
    if (_vec.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;

    // Sort vector and measure time
    clock_t start = clock();
    mergeInsertSort(_vec);
    _vecTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    // Sort deque and measure time
    start = clock();
    mergeInsertSort(_deq);
    _deqTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC * 1000000;

    // Display after
    std::cout << "After: ";
    for (size_t i = 0; i < _vec.size() && i < 5; ++i) {
        std::cout << _vec[i] << " ";
    }
    if (_vec.size() > 5) {
        std::cout << "[...]";
    }
    std::cout << std::endl;

    // Display times
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector: " << std::fixed << std::setprecision(5)
              << _vecTime << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque: " << std::fixed << std::setprecision(5)
              << _deqTime << " us" << std::endl;
}