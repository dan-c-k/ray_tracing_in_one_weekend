cmake_minimum_required(VERSION 3.10)
project(RTWeekend)

Ensure C++11 or later is used
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)


add_executable(basic_ppm main.cpp)
target_include_directories(basic_ppm PUBLIC include)mkd