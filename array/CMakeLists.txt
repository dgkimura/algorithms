cmake_minimum_required(VERSION 3.4)
project(algorithms.array)

set(SOURCES
    kadane.c
)
add_library(array SHARED ${SOURCES})
target_link_libraries(array)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(array_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
