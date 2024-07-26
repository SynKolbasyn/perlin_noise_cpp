#include <iostream>
#include <stdfloat>

#include "noise/math/vector.hpp"


using namespace sk::noise;


typedef std::float64_t t;


int main() {
    math::Vector<t> vector {{0, 0}, {1, 1}};

    std::cout << vector.to_unit().len() << std::endl;

    return 0;
}
