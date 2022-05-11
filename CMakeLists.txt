cmake_minimum_required(VERSION 3.0)
project(main)

option(BUILD_EXAMPLES "Build Log-Rush Examples" ON)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

add_subdirectory(src/)

if (${BUILD_EXAMPLES})
    add_subdirectory(examples/)
endif ()

install(TARGETS logrush)