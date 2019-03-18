cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost 1.6.0 COMPONENTS filesystem)

include_directories( ${MY_SOURCE_DIR}/project ${MY_SOURCE_DIR}/file )
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

add_library(Project project/Project.cpp project/Project.h project/Material.h project/Material.cpp project/DVD.h project/DVD.cpp)
add_library(File file/fileOperations.h file/fileOperations.cpp)
add_library(Information listInformation.cpp)

add_executable(trekstar trekstar.cpp)
target_link_libraries(trekstar Project)
target_link_libraries(trekstar File)
target_link_libraries(trekstar Information)
if(Boost_FOUND)
    target_link_libraries(trekstar ${Boost_LIBRARIES})
endif()
