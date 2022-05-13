cmake_minimum_required(VERSION 3.21)
project(logrushlib)

option(BUILD_EXAMPLES "Build examples" ON)

add_subdirectory(src/)

if(${BUILD_EXAMPLES})
    add_subdirectory(examples)
endif()