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
                            {3, "Update Project Materials"},
                            {4, "Remove Project"},
                            {5, "Cancel"}
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
                    else if ( commandInput == 2 || commandInput == 3 )
                    {
                        std::cout << std::string(80, '-') << std::endl;
                        TrekStar::Information::displayAllProjects(projects);
                        std::cout << std::string(80, '-') << std::endl;

                        int projectID = TrekStar::Command::GetIndexInput(projects.size(), "Project ID");
                        commandHandler.clearConsole();

                        if ( commandInput == 3 )
                        {
                            TrekStar::Information::updateProject(projects, projectID);
                        }
                        else
                        {
                            TrekStar::Information::updateMaterials(projects, projectID);
                        }
                    }
                    else if ( commandInput == 4 )
                    {
                        
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