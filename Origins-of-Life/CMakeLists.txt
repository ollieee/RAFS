cmake_minimum_required(VERSION 3.10)
project(Origins_of_Life)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

include_directories(include)
include_directories(include/Solvers)
include_directories(src)
include_directories(src/Types)

add_executable(Origins_of_Life
        tests/small/smallTests.cpp
        include/TestCaseProcessor.h
        include/Solvers/RAFSolver1.h
        src/Types/RAFAliases.h
        src/Types/Reaction.h
        src/Types/FoodCRS.h
        include/RAF.h)
