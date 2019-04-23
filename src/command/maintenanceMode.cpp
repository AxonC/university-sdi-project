#include <iostream>

#include "maintenanceMode.h"
#include "CommandHandler.h"
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
                    {1, "add project"},
                    {2, "update project"},
                    {3, "save changes to file"},
                    {4, "go back"}
            },
            "Maintenance Mode"
    );

    int commandInput  = 0;
    while ( commandInput != 4 )
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
            else if ( commandInput == 2 )
            {
                std::cout << std::string(80, '-') << std::endl;
                TrekStar::Information::displayAllProjects(projects);
                std::cout << std::string(80, '-') << std::endl;

                int projectID;
                std::cout << "Project ID: ";
                std::cin >> projectID;
                commandHandler.clearConsole();

                TrekStar::Information::updateProject(projects, projectID);
            }
            else if ( commandInput == 3 )
            {
                TrekStar::Information::save(projects, FILE_PATH);
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