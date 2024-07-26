//
// Created by Andrew on 26.07.2024.
//

#ifndef VECTOR_HPP
#define VECTOR_HPP


#include <cmath>

#include "point.hpp"


namespace sk::noise::math {


    template<typename T>
    class Vector {
    public:
        Vector();
        Vector(Point<T> a, Point<T> b);
        T x();
        T y();
        T len();
        Vector to_unit();

    private:
        Point<T> a, b;
    };


    template<typename T>
    Vector<T>::Vector() {
        a = Point<T> {};
        b = Point<T> {};
    }


    template<typename T>
    Vector<T>::Vector(Point<T> a, Point<T> b) {
        this->a = a;
        this->b = b;
    }


    template<typename T>
    T Vector<T>::x() {
        return b.x - a.x;
    }


    template<typename T>
    T Vector<T>::y() {
        return b.y - a.y;
    }


    template<typename T>
    T Vector<T>::len() {
        return std::sqrt(x() * x() + y() * y());
    }


    template<typename T>
    Vector<T> Vector<T>::to_unit() {
        T len = this->len();
        return Vector {{0, 0}, {x() / len, y() / len}};
    }


}


#endif //VECTOR_HPP
