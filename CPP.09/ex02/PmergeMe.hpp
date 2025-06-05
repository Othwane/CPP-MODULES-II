#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <ctime>
#include <utility>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    double _vecTime;
    double _deqTime;

    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);

    template <typename Container>
    void mergeInsertSort(Container& c);

    template <typename Container>
    void merge(Container& c, Container& left, Container& right);

    template <typename Container>
    void insertionSort(Container& c);

public:
    PmergeMe(int argc, char** argv);
    ~PmergeMe();

    void sortAndDisplay();
};

#endif