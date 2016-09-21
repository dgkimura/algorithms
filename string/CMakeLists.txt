cmake_minimum_required(VERSION 3.4)
project(algorithms.string)

set(SOURCES
    kmp.c
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_library(algorithms SHARED ${SOURCES})
target_link_libraries(algorithms)

set_property(TARGET algorithms PROPERTY CXX_STANDARD 11)
set_target_properties(algorithms
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
)

set(algorithms_DIR ${CMAKE_CURRENT_SOURCE_DIR} PARENT_SCOPE)
