cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/controller ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/structures ${MY_SOURCE_DIR}/file ${MY_SOURCE_DIR}/information)

add_executable(trekstar main.cpp)

# models
add_library(Bluray_Model model/material/Bluray.h model/material/Bluray.cpp)
add_library(BoxSet_Model model/material/BoxSet.h model/material/BoxSet.cpp)
add_library(DoubleSideDVD_Model model/material/DoubleSideDVD.h model/material/DoubleSideDVD.cpp)
add_library(DVD_Model model/material/DVD.h model/material/DVD.cpp)
add_library(DVDSide_Model model/material/DVDSide.h model/material/DVDSide.cpp)
add_library(Material_Model model/material/Material.h model/material/Material.cpp model/material/MaterialInterface.h)
add_library(MaterialFactory_Model model/material/MaterialFactory.h model/material/MaterialFactory.cpp)
add_library(VHS_Model model/material/VHS.h model/material/VHS.cpp)
add_library(Crew_Model model/people/Crew.h model/people/Crew.cpp)
add_library(Project_Model model/project/Project.h model/project/Project.cpp model/project/ProjectInterface.h)
target_link_libraries(trekstar Bluray_Model BoxSet_Model DoubleSideDVD_Model DVD_Model DVDSide_Model Material_Model MaterialFactory_Model VHS_Model Crew_Model Project_Model)

# views
add_library(ConsoleMessage_View view/ConsoleMessageView.h view/ConsoleMessageView.cpp view/ViewInterface.h)
add_library(Project_View view/project/ProjectView.h view/project/ProjectView.cpp)
add_library(Material_View view/material/MaterialView.h view/material/MaterialView.cpp)
target_link_libraries(trekstar ConsoleMessage_View Project_View Material_View)

# controllers
add_library(Controller controller/BaseController.h controller/BaseController.cpp controller/ControllerInterface.h)
add_library(Project_Controller controller/project/ProjectController.h controller/project/ProjectController.cpp)
add_library(Material_Controller controller/material/MaterialController.h controller/material/MaterialController.cpp)
target_link_libraries(trekstar Controller Project_Controller Material_Controller)

# algorithms
add_library(MergeSort algorithms/MergeSort.h algorithms/MergeSort.cpp)
add_library(BinarySearch algorithms/BinarySearch.h algorithms/BinarySearch.cpp)
target_link_libraries(trekstar MergeSort BinarySearch)

# functions
add_library(File file/fileOperations.h file/fileOperations.cpp)
add_library(Information information/listInformation.h information/addInformation.h information/saveInformation.h information/listInformation.cpp information/addInformation.cpp information/saveInformation.cpp information/SequentialBrowser.h information/SequentialBrowser.cpp view/ConsoleMessageView.cpp view/ConsoleMessageView.h)
add_library(CommandHandler command/CommandHandler.h command/CommandHandler.cpp)
target_link_libraries(trekstar File Information CommandHandler)

# data structures
add_library(structures INTERFACE)
target_include_directories(structures INTERFACE structures/Stack.h)
add_library(nlohmann_json INTERFACE)
target_include_directories(nlohmann_json INTERFACE lib/json.hpp)
target_link_libraries(trekstar structures nlohmann_json)