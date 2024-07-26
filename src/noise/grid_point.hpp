//
// Created by Andrew on 26.07.2024.
//

#ifndef GRID_POINT_HPP
#define GRID_POINT_HPP


#include <cmath>
#include <random>

#include "random.hpp"
#include "math/point.hpp"
#include "math/vector.hpp"


namespace sk::noise {


    template<typename T>
    class Grid_Point {
    public:
        Grid_Point();
        Grid_Point(T x, T y);
        math::Point<T> point;
        math::Vector<T> unit_vector;
    };


    template<typename T>
    Grid_Point<T>::Grid_Point() {
        point = math::Point<T> {};
        unit_vector = math::Vector<T> {};
    }


    template<typename T>
    Grid_Point<T>::Grid_Point(T x, T y) {
        T theta = float_random<T>(0.0, M_PI * 2);
        point = math::Point<T> {x, y};
        unit_vector = math::Vector<T> {
            math::Point<T> {},
            math::Point<T> {std::cos(theta), std::sin(theta)},
        };
    }



}


#endif //GRID_POINT_HPP
