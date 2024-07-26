#include <iostream>
#include <ostream>
#include <stdfloat>

#include "noise/noise.hpp"


using namespace sk::noise;


typedef std::float64_t tp;


int main() {
    SEED = time(nullptr);

    Noise<tp> noise {1000, 1000, 3};
    tp m = 0.0;
    while (true) {
        if (tp r = noise.get_noise(float_random(0.0, 10.0), float_random(0.0, 10.0)); std::abs(r) > m) {
            m = std::abs(r);
            std::cout << m << std::endl;
        }
    }

    return 0;
}
