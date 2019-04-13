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

add_library(Project project/Project.cpp project/Project.h project/ProjectController.cpp project/ProjectController.h)
add_library(Material material/Material.h material/Material.cpp material/DVDSide.h material/DVDSide.cpp material/DVD.h material/DVD.cpp material/MaterialFactory.h material/MaterialFactory.cpp material/BoxSet.h material/BoxSet.cpp  material/SingleSideDVD.cpp material/SingleSideDVD.h material/DoubleSideDVD.cpp material/DoubleSideDVD.h)
add_library(File file/fileOperations.h file/fileOperations.cpp)
add_library(People people/Crew.cpp people/Crew.h)
add_library(Information listInformation.cpp addInformation.cpp)

# data structures
add_library(Structures SHARED structures/Stack.h)
add_library(nlohmann_json SHARED lib/json.hpp)
#required to compile the header only template class
set_target_properties(Structures PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(nlohmann_json PROPERTIES LINKER_LANGUAGE CXX)

add_executable(trekstar trekstar.cpp structures/Stack.h)
target_link_libraries(trekstar Project People Material File Information Structures nlohmann_json)
target_include_directories(trekstar PUBLIC Structures)
if(Boost_FOUND)
    target_link_libraries(trekstar ${Boost_LIBRARIES})
endif()