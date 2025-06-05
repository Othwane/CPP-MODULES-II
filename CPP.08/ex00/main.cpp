#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);
        lst.push_back(50);

        std::vector<int>::iterator vec_it = easyfind(vec, 3);
        std::cout << "Found in vector: " << *vec_it << std::endl;

        std::list<int>::iterator lst_it = easyfind(lst, 30);
        std::cout << "Found in list: " << *lst_it << std::endl;

        easyfind(vec, 42);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}