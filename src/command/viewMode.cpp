#include <iostream>

#include "viewMode.h"
#include "CommandHandler.h"
#include "../information/saveInformation.h"

namespace TrekStar
{
    namespace Command
    {
        void viewMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "list projects"},
                            {2, "search projects"},
                            {3, "list materials"},
                            {4, "go back"}
                    },
                    "View Mode"
            );

            int commandInput;
            while ( commandInput != 4 )
            {
                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();

                if ( commandHandler.isValidCommand(commandInput) )
                {
                    switch ( commandInput )
                    {
                        case 1 :
                            TrekStar::Information::listProjects(projects);
                            break;
                        case 2 :
                            TrekStar::Information::searchProjects(projects);
                            break;
                        case 3 :
                            try
                            {
                                TrekStar::Information::listMaterials(projects, 1);
                            }
                            catch ( std::invalid_argument & )
                            {
                                std::cout << "Invalid parameter, please try again." << std::endl;
                            }
                            break;
                        default :
                            std::cout << "Invalid command..." << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid command..." << std::endl << std::endl;
                }
            }
        }
    }
}
