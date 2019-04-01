cmake_minimum_required(VERSION 3.10.3)

set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../src)

add_executable(tests tests.cpp exampleTest.cpp tests/ProjectTest.cpp tests/MaterialTest.cpp tests/StackTest.cpp)
gtest_discover_tests(tests)
target_link_libraries(tests gtest gtest_main gmock Project Material People Structures)
