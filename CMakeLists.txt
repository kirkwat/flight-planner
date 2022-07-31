cmake_minimum_required(VERSION 3.15)
project(flight_planner)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_DEBUG “-O3”)

add_executable(flight_planner src/main.cpp src/DSAdjList.cpp src/DSAdjList.h src/DSList.h src/DSStack.h src/DSString.cpp src/DSString.h src/Planner.cpp src/Planner.h src/test.cpp src/Origin.cpp src/Origin.h src/Destination.cpp src/Destination.h src/Flight.cpp src/Flight.h src/Path.cpp src/Path.h)

