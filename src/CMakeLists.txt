cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories( ${MY_SOURCE_DIR}/project ${MY_SOURCE_DIR}/material ${MY_SOURCE_DIR}/people ${MY_SOURCE_DIR}/structures ${MY_SOURCE_DIR}/file ${MY_SOURCE_DIR}/information )

# classes
add_library(Project project/Project.cpp project/Project.h project/ProjectController.cpp project/ProjectController.h)
add_library(Material material/Material.h material/Material.cpp material/DVDSide.h material/DVDSide.cpp material/DVD.h material/DVD.cpp material/MaterialFactory.h material/MaterialFactory.cpp material/BoxSet.h material/BoxSet.cpp material/DoubleSideDVD.cpp material/DoubleSideDVD.h)
add_library(People people/Crew.cpp people/Crew.h)
add_library(Command command/CommandHandler.h command/CommandHandler.cpp)

# functions
add_library(File file/fileOperations.h file/fileOperations.cpp)
add_library(Information information/listInformation.h information/addInformation.h information/saveInformation.h information/listInformation.cpp information/addInformation.cpp information/saveInformation.cpp)

# data structures
add_library(Structures SHARED structures/Stack.h)
add_library(nlohmann_json SHARED lib/json.hpp)

# required to compile the header only template class
set_target_properties(Structures PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(nlohmann_json PROPERTIES LINKER_LANGUAGE CXX)

add_executable(trekstar main.cpp)
target_link_libraries(trekstar Project People Command Material File Information Structures nlohmann_json)
target_include_directories(trekstar PUBLIC Structures)