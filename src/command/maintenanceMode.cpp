#include <iostream>

#include "maintenanceMode.h"
#include "CommandHandler.h"
#include "userInput.h"
#include "../information/listInformation.h"
#include "../information/addInformation.h"
#include "../information/saveInformation.h"
#include "../information/updateInformation.h"

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

            int commandInput  = 0;
            while ( commandInput != 5 )
            {
                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();

                if ( commandHandler.isValidCommand(commandInput) )
                {
                    if ( commandInput == 1 )
                    {
                        TrekStar::Information::addProject(projects);
                    }
                    else
                    {
                        std::cout << std::string(80, '-') << std::endl;
                        TrekStar::Information::displayAllProjects(projects);
                        std::cout << std::string(80, '-') << std::endl;

                        int projectIndex = TrekStar::Command::GetIndexInput(projects.size(), "Project ID");
                        commandHandler.clearConsole();

                        if ( commandInput == 2 )
                        {
                            TrekStar::Information::updateProject(projects, projectIndex);
                        }
                        else if ( commandInput == 3 )
                        {
                            projects.erase(projects.begin() + projectIndex);
                        }
                        else if ( commandInput == 4 )
                        {
                            TrekStar::Information::updateMaterials(projects, projectIndex);
                        }
                        else
                        {
                            // TO DO: Remove Project Materials.
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