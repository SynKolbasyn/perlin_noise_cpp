cmake_minimum_required(VERSION 3.29)
project(perlin_noise)

set(CMAKE_CXX_STANDARD 26)

add_executable(perlin_noise src/main.cpp
        src/noise/math/point.hpp
        src/noise/math/vector.hpp)
