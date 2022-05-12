cmake_minimum_required(VERSION 3.0)
project(log-rush)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

target_include_directories(logrush PUBLIC ../include/)

set(SRC_FILES
    "../include/logrush.hpp"

    "../include/LogRushClient.hpp"
    "../include/LogRushStream.hpp"
    "../include/json/json.hpp"
    "../include/http/http.hpp"

    "LogRushClient.cpp"
    "LogRushStream.cpp"

    "http/http.cpp"
)

add_library(logrush STATIC ${SRC_FILES})
target_link_libraries(logrush CURL::libcurl)
