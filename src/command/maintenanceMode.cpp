#include <iostream>

#include "maintenanceMode.h"
#include "CommandHandler.h"
#include "userInput.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"
#include "../information/listInformation.h"

namespace TrekStar
{
    namespace Command
    {
        void maintenanceMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Add Project"},
                            {2, "Update Project"},
                            {3, "Remove Project"},
                            {4, "Update Project Materials"},
                            {5, "Remove Project Materials"},
                            {6, "Cancel"}
                    },
                    "Maintenance Mode"
            );

            int commandInput = 0;
            while ( commandInput != 5 )
            {
                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();

                if ( commandHandler.isValidCommand(commandInput) )
                {
                    if ( commandInput == 1 )
                    {
                        TrekStar::Project::Project currentProject;

                        TrekStar::Project::ProjectView view(currentProject);
                        TrekStar::Project::ProjectController controller(currentProject, view);

                        controller.UpdateAll();

                        projects.push_back(currentProject);
                    }
                    else
                    {
                        std::cout << std::string(80, '-') << std::endl;
                        TrekStar::Information::displayAllProjects(projects);
                        std::cout << std::string(80, '-') << std::endl;

                        int projectIndex = TrekStar::Command::GetIndexInput(projects.size(), "Project ID");
                        commandHandler.clearConsole();

                        TrekStar::Project::ProjectView view(projects.at(projectIndex));
                        TrekStar::Project::ProjectController controller(projects.at(projectIndex), view);

                        if ( commandInput == 2 )
                        {
                            controller.UpdateProject();
                        }
                        else if ( commandInput == 3 )
                        {
                            projects.erase(projects.begin() + projectIndex);
                        }
                        else if ( commandInput == 4 )
                        {
                            controller.UpdateMaterials();
                        }
                        else
                        {
                            controller.RemoveMaterial();
                        }
                    }
                }
                else
                {
                    std::cout << "Invalid command..." << std::endl;
                }
            }
        }
    }
}