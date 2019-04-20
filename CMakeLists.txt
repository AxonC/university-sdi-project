cmake_minimum_required(VERSION 3.1)
project(trekstar)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

add_subdirectory(src)
#add_subdirectory(tests)

#enable_testing()
