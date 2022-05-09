cmake_minimum_required(VERSION 3.0)
project(log-rush)

set(CMAKE_CXX_STANDARD 17)

find_package(CURL REQUIRED)

include_directories("../include/")

set(SRC_FILES
    "main.cpp"
    "LogRushClient.cpp"
    "LogRushStream.cpp"

    "http/http.cpp"
)

add_library(logrush STATIC ${SRC_FILES})
target_link_libraries(logrush CURL::libcurl)
