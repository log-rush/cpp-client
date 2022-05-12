cmake_minimum_required(VERSION 3.15)
project(logrush
    DESCRIPTION "logrush client for c++"
    VERSION 0.0.1
)

find_package(CURL REQUIRED)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(namespace "logrush")
set(public_headers
    "../include/logrush/logrush.h"
    "../include/logrush/LogRushClient.h"
    "../include/logrush/LogRushStream.h"
)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}    
    PRIVATE
        "LogRushClient.cpp"
        "LogRushStream.cpp"
        "http/http.cpp"
)
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)

include(Install)