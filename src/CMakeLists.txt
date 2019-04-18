cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories( ${MY_SOURCE_DIR}/project ${MY_SOURCE_DIR}/material ${MY_SOURCE_DIR}/people ${MY_SOURCE_DIR}/structures ${MY_SOURCE_DIR}/file ${MY_SOURCE_DIR}/information )

# classes
add_library(Project project/Project.cpp project/Project.h project/ProjectController.cpp project/ProjectController.h)
add_library(Material material/Material/Material.h material/Material/Material.cpp)
add_library(MaterialFactory material/MaterialFactory/MaterialFactory.h material/MaterialFactory/MaterialFactory.cpp)
add_library(DVDSide material/DVDSide/DVDSide.h material/DVDSide/DVDSide.cpp)
add_library(DVD material/DVD/DVD.h material/DVD/DVD.cpp)
add_library(DoubleSideDVD material/DoubleSideDVD/DoubleSideDVD.h material/DoubleSideDVD/DoubleSideDVD.cpp)
add_library(Bluray material/Bluray/Bluray.h material/Bluray/Bluray.cpp material/VHS/VHS.cpp material/VHS/VHS.h)
add_library(BoxSet material/BoxSet/BoxSet.h material/BoxSet/BoxSet.cpp)
add_library(VHS material/VHS/VHS.h material/VHS/VHS.cpp)
add_library(People people/Crew.cpp people/Crew.h)
add_library(Command command/CommandHandler.h command/CommandHandler.cpp)

add_library(Model Model.h Model.cpp)

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
target_link_libraries(trekstar Project People Command Material MaterialFactory DVDSide DVD DoubleSideDVD Bluray BoxSet File Information Model Structures nlohmann_json)
target_include_directories(trekstar PUBLIC Structures)