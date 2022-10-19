cmake_minimum_required(VERSION 3.8.0)
project(Box-simulator)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(${PROJECT_NAME}
    BoxSim.hpp
    BoxSim.cpp)
    
add_executable(BoxSim "BoxSim.cpp")

