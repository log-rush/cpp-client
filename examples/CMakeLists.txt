cmake_minimum_required(VERSION 3.21)
project(examples-libname)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(batch_logger_example batch_logger_example.cpp)
target_link_libraries(batch_logger_example logrush)

add_executable(basic_logger_example basic_logger_example.cpp)
target_link_libraries(basic_logger_example logrush)