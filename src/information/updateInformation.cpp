#include <iostream>

#include "updateInformation.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../command/CommandHandler.h"

using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<TrekStar::Project::Project> & projects, int projectID)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Edit Title"},
                            {2, "Edit Summary"},
                            {3, "Edit Released"},
                            {4, "Edit PlayingInTheatres"},
                            {5, "Edit Existing Keywords"},
                            {6, "CANCEL"}
                    },
                    "Update Project"
            );

            TrekStar::Project::Project currentProject;

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

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            switch ( commandInput )
            {
                case 1:
                    controller.UpdateTitle();
                    break;
                case 2:
                    controller.UpdateSummary();
                    break;
                case 3:
                    controller.UpdateReleased();
                    break;
                case 4:
                    controller.UpdatePlayingInTheatres();
                    break;
                case 5:
                    controller.UpdateKeyword();
                    break;
                default:
                    break;
            }
        }
    }
}
