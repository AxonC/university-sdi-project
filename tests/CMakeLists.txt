cmake_minimum_required(VERSION 3.1)

set (CMAKE_CXX_STANDARD 11)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests tests.cpp exampleTest.cpp)
target_link_libraries(tests ${GTEST_LIBRARIES})
