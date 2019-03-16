cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories( ${MY_SOURCE_DIR}/project ${MY_SOURCE_DIR}/file )

add_library(Project project/Project.cpp project/Project.h project/Material.h project/Material.cpp project/DVD.h project/DVD.cpp)
add_library(File file/fileOperations.h file/fileOperations.cpp)

add_executable(trekstar trekstar.cpp)
target_link_libraries(trekstar Project)
target_link_libraries(trekstar File)