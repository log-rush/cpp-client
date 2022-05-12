cmake_minimum_required(VERSION 3.0)
project(log-rush_examples)

set(CMAKE_CXX_STANDARD 17)

add_executable(logrush_basic_example basic_logger_example.cpp)
target_link_libraries(logrush_basic_example logrush)

add_executable(logrush_batch_example batch_logger_example.cpp)
target_link_libraries(logrush_batch_example logrush)
