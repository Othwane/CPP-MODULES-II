// Data.hpp
#ifndef DATA_HPP
#define DATA_HPP

#include <stdint.h>

struct Data {
    int value;
    std::string name;
};

class Serializer {
private:
    Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);
    ~Serializer();

public:
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif
