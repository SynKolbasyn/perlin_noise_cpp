//
// Created by Andrew on 26.07.2024.
//

#ifndef NOISE_HPP
#define NOISE_HPP


#include <cstdint>
#include <vector>

#include "grid.hpp"


namespace sk::noise {


    template<typename T>
    class Noise {
    public:
        Noise();
        Noise(uint64_t x, uint64_t y, uint64_t octaves);

        T get_noise(T x, T y);

    private:
        std::vector<Grid<T>> grids;
    };


    template<typename T>
    Noise<T>::Noise() {
        grids = std::vector<Grid<T>> {};
    }


    template<typename T>
    Noise<T>::Noise(const uint64_t x, const uint64_t y, const uint64_t octaves) {
        grids = std::vector<Grid<T>> {};
        for (uint64_t octave = 0; octave < octaves; ++octave) {
            const auto multiplier = static_cast<uint64_t>(std::pow(2, octave));
            grids.push_back(Grid<T> {
                (x + 1) * multiplier,
                (y + 1) * multiplier,
                octave
            });
        }
    }


    template<typename T>
    T Noise<T>::get_noise(T x, T y) {
        math::Point<T> point {x, y};
        T result = 0.0;
        for (auto grid : grids) {
            result += grid.process(point);
        }
        return result;
    }



}


#endif //NOISE_HPP
