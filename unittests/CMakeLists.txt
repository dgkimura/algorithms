cmake_minimum_required(VERSION 3.4)
project(unittests)

include(ExternalProject)

ExternalProject_Add(
    gtest
    URL https://github.com/google/googletest/archive/release-1.7.0.zip
    URL_HASH SHA256=b58cb7547a28b2c718d1e38aee18a3659c9e3ff52440297e965f5edffe34b6d0
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)

set(SOURCES
    kmp_unittests.cpp
    manacher_unittests.cpp
)

add_executable(all_unittests ${SOURCES})
add_dependencies(all_unittests gtest)
add_dependencies(all_unittests algorithms)

set_property(TARGET all_unittests PROPERTY CXX_STANDARD 11)

target_link_libraries(all_unittests
    PRIVATE
        algorithms
        ${CMAKE_CURRENT_BINARY_DIR}/gtest-prefix/src/gtest-build/${CMAKE_STATIC_LIBRARY_PREFIX}gtest_main${CMAKE_STATIC_LIBRARY_SUFFIX}
        ${CMAKE_CURRENT_BINARY_DIR}/gtest-prefix/src/gtest-build/${CMAKE_STATIC_LIBRARY_PREFIX}gtest${CMAKE_STATIC_LIBRARY_SUFFIX}
)

include_directories(${CMAKE_CURRENT_BINARY_DIR}/gtest-prefix/src/gtest/include)
include_directories(${algorithms_DIR})
