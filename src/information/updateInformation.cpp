#include <iostream>

#include "updateInformation.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"
#include "../command/CommandHandler.h"

using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;
using TrekStar::Material::MaterialController;
using TrekStar::Material::MaterialView;

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<TrekStar::Project::Project> & projects, int projectID)
        {
            ProjectController controller;

            for ( auto & project: projects )
            {
                if ( project.GetId() == projectID )
                {
                    ProjectView view(project);
                    controller = ProjectController(project, view);
                    break;
                }
            }

            controller.UpdateProject();
        }

        void updateMaterials(std::vector<TrekStar::Project::Project> & projects, int projectID)
        {
            ProjectController controller;

            for ( auto & project: projects )
            {
                if ( project.GetId() == projectID )
                {
                    ProjectView view(project);
                    controller = ProjectController(project, view);
                    break;
                }
            }

            controller.UpdateMaterials();

//            commandHandler.displayCommands();
//            int commandInput = commandHandler.getUserInput();
//            commandHandler.clearConsole();
//
//            switch ( commandInput )
//            {
//                case 1:
//                    controller.UpdateTitle();
//                    break;
//                case 2:
//                    controller.UpdateSummary();
//                    break;
//                case 3:
//                    controller.UpdateReleased();
//                    break;
//                case 4:
//                    controller.UpdatePlayingInTheatres();
//                    break;
//                case 5:
//                    controller.UpdateKeyword();
//                    break;
//                default:
//                    break;
//            }
        }
    }
}
