cmake_minimum_required(VERSION 3.10.3)

set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../src)
include_directories(../src/lib)

add_executable(tests tests.cpp ../src/pch.h tests/ProjectTest.cpp tests/DVDTest.cpp tests/StackTest.cpp tests/BaseMaterialTest.cpp mock/MockProject.h mock/MockProjectView.h)
gtest_discover_tests(tests)
target_link_libraries(tests gtest gtest_main gmock Models Views Controllers Algorithms Functions structures)
