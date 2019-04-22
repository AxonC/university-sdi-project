#include <iostream>

#include "maintainenceMode.h"
#include "CommandHandler.h"
#include "../information/addInformation.h"
#include "../information/saveInformation.h"

namespace TrekStar
{
    namespace Command
    {
        void maintainenceMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "add project"},
                            {2, "save changes to file"},
                            {3, "go back"}
                    },
                    "Maintainence Mode"
            );

            int commandInput;
            while ( commandInput != 3 )
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