//
// Created by Andrew on 26.07.2024.
//

#ifndef GRID_HPP
#define GRID_HPP


#include <cstdint>
#include <vector>

#include "grid_point.hpp"


namespace sk::noise {


    template<typename T>
    class Grid {
    public:
        Grid();
        Grid(uint64_t x, uint64_t y, uint64_t scale);

        T process(math::Point<T> point);

    private:
        uint64_t scale;
        std::vector<std::vector<Grid_Point<T>>> points;

        T interpolate(T a, T b, T t);

        T smoother_step(T t);
    };


    template<typename T>
    Grid<T>::Grid() {
        scale = 0;
        points = std::vector<std::vector<Grid_Point<T>>> {};
    }


    template<typename T>
    Grid<T>::Grid(const uint64_t x, const uint64_t y, uint64_t scale) {
        this->scale = scale;
        points = std::vector<std::vector<Grid_Point<T>>> {};

        for (uint64_t i = 0; i < y; ++i) {
            std::vector<Grid_Point<T>> points_line {};
            for (uint64_t j = 0; j < x; ++j) {
                points_line.push_back(Grid_Point<T> {static_cast<T>(j), static_cast<T>(i)});
            }
            points.push_back(points_line);
        }
    }


    template<typename T>
    T Grid<T>::process(math::Point<T> point) {
        T tx = point.x - std::floor(point.x);
        T ty = point.y - std::floor(point.y);

        Grid_Point<T> lbp = points[static_cast<uint64_t>(std::floor(point.y))][static_cast<uint64_t>(std::floor(point.x))];
        Grid_Point<T> rbp = points[static_cast<uint64_t>(std::floor(point.y))][static_cast<uint64_t>(std::ceil(point.x))];
        Grid_Point<T> lup = points[static_cast<uint64_t>(std::ceil(point.y))][static_cast<uint64_t>(std::floor(point.x))];
        Grid_Point<T> rup = points[static_cast<uint64_t>(std::ceil(point.y))][static_cast<uint64_t>(std::ceil(point.x))];

        T a1 = lbp.unit_vector * math::Vector<T> {lbp.point, point};
        T b1 = rbp.unit_vector * math::Vector<T> {rbp.point, point};
        T a2 = lup.unit_vector * math::Vector<T> {lup.point, point};
        T b2 = rup.unit_vector * math::Vector<T> {rup.point, point};

        T a3 = interpolate(a1, b1, tx);
        T b3 = interpolate(a2, b2, tx);

        return interpolate(a3, b3, ty) * std::pow(0.5, scale - 1);
    }


    template<typename T>
    T Grid<T>::interpolate(T a, T b, T t) {
        return a + smoother_step(t) * (b - a);
    }


    template<typename T>
    T Grid<T>::smoother_step(T t) {
        return t * t * t * (t * (6.0 * t - 15.0) + 10.0);
    }


}


#endif //GRID_HPP
