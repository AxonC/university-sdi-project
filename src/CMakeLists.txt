cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories( ${MY_SOURCE_DIR}/project ${MY_SOURCE_DIR}/material ${MY_SOURCE_DIR}/people ${MY_SOURCE_DIR}/structures ${MY_SOURCE_DIR}/file ${MY_SOURCE_DIR}/information ${MY_SOURCE_DIR}/GUI )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH /usr/local/opt/qt5/lib/cmake)

find_package(Qt5 REQUIRED Qml Quick QuickWidgets QuickControls2 Gui)
include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES GUI/main.qml GUI/qml.qrc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")

#qt5_add_resources(qml_QRC GUI/main.qml GUI/qml.qrc)

find_package(Qt5Core)
get_target_property(QtCore_location Qt5::Core LOCATION)

find_package(Qt5Quick)
get_target_property(QtCore_location Qt5::Quick LOCATION)

find_package(Qt5Widgets)
get_target_property(QtCore_location Qt5::Widgets LOCATION)

foreach(plugin ${Qt5Network_PLUGINS})
    get_target_property(_loc ${plugin} LOCATION)
    message("Plugin ${plugin} is at location ${_loc}")
endforeach()

# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
set_target_properties(Qt5::Core PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Widgets PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")
set_target_properties(Qt5::Quick PROPERTIES MAP_IMPORTED_CONFIG_COVERAGE "RELEASE")

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

add_library(Backend GUI/backend.h GUI/backend.cpp)

# functions
add_library(File file/fileOperations.h file/fileOperations.cpp)
add_library(Information information/listInformation.h information/addInformation.h information/saveInformation.h information/listInformation.cpp information/addInformation.cpp information/saveInformation.cpp)

# data structures
add_library(Structures SHARED structures/Stack.h)
add_library(nlohmann_json SHARED lib/json.hpp)

# required to compile the header only template class
set_target_properties(Structures PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(nlohmann_json PROPERTIES LINKER_LANGUAGE CXX)

# Populate a CMake variable with the sources
set(trekstar_SRCS main.cpp)
# Tell CMake to create the helloworld executable
add_executable(trekstar ${trekstar_SRCS} ${qml_QRC})
# Use the Widgets module from Qt 5
target_link_libraries(trekstar Qt5::Core Qt5::Widgets Qt5::Qml Qt5::Quick Qt5::QuickWidgets Qt5::QuickControls2 Backend Project People Command Material MaterialFactory DVDSide DVD DoubleSideDVD Bluray BoxSet File Information Model Structures nlohmann_json)
target_include_directories(trekstar PUBLIC Structures)