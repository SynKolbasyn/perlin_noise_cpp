//
// Created by Andrew on 26.07.2024.
//

#ifndef RANDOM_HPP
#define RANDOM_HPP


#include <cstdint>


inline uint64_t SEED = 0;
constexpr uint64_t A = 1103515245;
constexpr uint64_t C = 12345;
constexpr uint64_t M = 2147483648;


inline uint64_t default_random();


template<typename T>
T int_random(T from = 0, T to = UINT64_MAX);


template<typename T>
T float_random(T from = 0.0, T to = 1.0);


template<typename T>
T int_random(T from, T to) {
    return from + default_random() % (to - from);
}


template<typename T>
T float_random(T from, T to) {
    T result = static_cast<T>(default_random()) / static_cast<T>(M);
    return result * (to - from) + from;
}


inline uint64_t default_random() {
    SEED = (A * SEED + C) % M;

    return SEED;
}


#endif //RANDOM_HPP
