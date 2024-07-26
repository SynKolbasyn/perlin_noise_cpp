#include <iostream>
#include <stdfloat>

#include "noise/grid_point.hpp"
#include "noise/random.hpp"


using namespace sk::noise;


typedef std::float64_t t;


int main() {
    SEED = time(nullptr);

    Grid_Point<t> grid_point {0, 0};

    std::cout <<
        grid_point.unit_vector.x() << " | " <<
        grid_point.unit_vector.y() << " -> " <<
        grid_point.unit_vector.len() <<
    std::endl;

    return 0;
}
