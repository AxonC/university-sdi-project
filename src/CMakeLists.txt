cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 11)

include_directories(${MY_SOURCE_DIR}/model ${MY_SOURCE_DIR}/controller ${MY_SOURCE_DIR}/view ${MY_SOURCE_DIR}/structures ${MY_SOURCE_DIR}/file ${MY_SOURCE_DIR}/information)

# models
set(Base_Model model/Model.h model/Model.cpp)
set(Project_Model model/project/Project.h model/project/Project.cpp model/project/ProjectInterface.h)
set(BoxOfficeReport_Model model/project/BoxOfficeReport.cpp model/project/BoxOfficeReport.h model/project/BoxOfficeReportInterface.h)
set(Crew_Model model/people/Crew.h model/people/Crew.cpp model/people/CrewInterface.h)
set(Bluray_Model model/material/Bluray.h model/material/Bluray.cpp)
set(BoxSet_Model model/material/BoxSet.h model/material/BoxSet.cpp)
set(DoubleSideDVD_Model model/material/DoubleSideDVD.h model/material/DoubleSideDVD.cpp model/material/DoubleSideDVDInterface.h)
set(DVD_Model model/material/DVD.h model/material/DVD.cpp model/material/DVDInterface.h)
set(DVDSide_Model model/material/DVDSide.h model/material/DVDSide.cpp)
set(Material_Model model/material/Material.h model/material/Material.cpp model/material/MaterialInterface.h)
set(MaterialFactory_Model model/material/MaterialFactory.h model/material/MaterialFactory.cpp)
set(VHS_Model model/material/VHS.h model/material/VHS.cpp)
add_library(Models ${Base_Model} ${Project_Model} ${BoxOfficeReport_Model} ${Crew_Model} ${Bluray_Model} ${BoxSet_Model} ${DoubleSideDVD_Model} ${DVD_Model} ${DVDSide_Model} ${Material_Model} ${MaterialFactory_Model} ${VHS_Model})

# views
set(Base_View view/BaseView.h view/BaseView.cpp view/ViewInterface.h)
set(Project_View view/project/ProjectView.h view/project/ProjectView.cpp)
set(BoxOfficeReport_View view/project/BoxOfficeReportView.h view/project/BoxOfficeReportView.cpp)
set(Crew_View view/people/CrewView.h view/people/CrewView.cpp)
set(Material_View view/material/MaterialView.h view/material/MaterialView.cpp)
set(DVD_View view/material/DVDView.h view/material/DVDView.cpp)
set(DoubleSideDVD_View view/material/DoubleSideDVDView.h view/material/DoubleSideDVDView.cpp)
set(BoxSet_View view/material/BoxSetView.h view/material/BoxSetView.cpp)
set(VHS_View view/material/VHSView.h view/material/VHSView.cpp)
add_library(Views ${Base_View} ${Project_View} ${BoxOfficeReport_View} ${Crew_View} ${Material_View} ${DVD_View} ${DoubleSideDVD_View} ${BoxSet_View} ${VHS_View})

# controllers
set(Base_Controller controller/BaseController.h controller/BaseController.cpp controller/ControllerInterface.h)
set(Project_Controller controller/project/ProjectController.h controller/project/ProjectController.cpp)
set(BoxOfficeReport_Controller controller/project/BoxOfficeReportController.h controller/project/BoxOfficeReportController.cpp)
set(Crew_Controller controller/people/CrewController.h controller/people/CrewController.cpp)
set(Material_Controller controller/material/MaterialController.h controller/material/MaterialController.cpp)
set(DVD_Controller controller/material/DVDController.h controller/material/DVDController.cpp)
set(DoubleSideDVD_Controller controller/material/DoubleSideDVDController.h controller/material/DoubleSideDVDController.cpp)
set(BoxSet_Controller controller/material/BoxSetController.h controller/material/BoxSetController.cpp)
set(VHS_Controller controller/material/VHSController.h controller/material/VHSController.cpp)
add_library(Controllers ${Base_Controller} ${Project_Controller} ${BoxOfficeReport_Controller} ${Crew_Controller} ${Material_Controller} ${DVD_Controller} ${DoubleSideDVD_Controller} ${BoxSet_Controller} ${VHS_Controller})

# algorithms
set(MergeSort algorithms/MergeSort.h algorithms/MergeSort.cpp)
set(BinarySearch algorithms/BinarySearch.h algorithms/BinarySearch.cpp)
add_library(Algorithms ${MergeSort} ${BinarySearch})

# functions
set(File file/fileOperations.h file/fileOperations.cpp)
set(Information information/listInformation.h information/listInformation.cpp information/saveInformation.h information/saveInformation.cpp information/SequentialBrowser.h information/SequentialBrowser.cpp)
set(CommandHandler command/CommandHandler.h command/CommandHandler.cpp)
set(UserInput command/userInput.h command/userInput.cpp)
set(ViewMode command/viewMode.h command/viewMode.cpp)
set(MaintenanceMode command/maintenanceMode.h command/maintenanceMode.cpp)
add_library(Functions ${File} ${Information} ${CommandHandler} ${UserInput} ${ViewMode} ${MaintenanceMode})

# data structures
add_library(structures INTERFACE)
target_include_directories(structures INTERFACE structures/)

include_directories(. lib/)

add_executable(trekstar pch.h pch.cpp main.cpp lib/nlohmann/json.hpp)
target_link_libraries(trekstar Models Views Controllers Algorithms Functions structures)