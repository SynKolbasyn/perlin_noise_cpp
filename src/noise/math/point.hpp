//
// Created by Andrew on 26.07.2024.
//

#ifndef POINT_HPP
#define POINT_HPP


namespace sk::noise::math {


    template<typename T>
    class Point {
    public:
        Point();
        Point(T x, T y);
        T x, y;
    };


    template<typename T>
    Point<T>::Point() {
        x = 0;
        y = 0;
    }


    template<typename T>
    Point<T>::Point(T x, T y) {
        this->x = x;
        this->y = y;
    }


}


#endif //POINT_HPP
