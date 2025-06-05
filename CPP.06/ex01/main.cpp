#include "Data.hpp"
#include <iostream>

int main() {
    Data data;
    data.value = 42;
    data.name = "Answer";

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    if (ptr == &data) {
        std::cout << "Serialization successful!" << std::endl;
        std::cout << "Data value: " << ptr->value << std::endl;
        std::cout << "Data name: " << ptr->name << std::endl;
    } else {
        std::cerr << "Serialization failed!" << std::endl;
    }

    return 0;
}