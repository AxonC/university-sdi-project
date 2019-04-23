#include <iostream>

#include "viewMode.h"
#include "CommandHandler.h"
#include "userInput.h"
#include "../information/saveInformation.h"

namespace TrekStar
{
    namespace Command
    {
        void viewMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "List Projects"},
                            {2, "Search Projects"},
                            {3, "Cancel"}
                    },
                    "View Mode"
            );

            int commandInput = 0;
            while ( commandInput != 3 )
            {
                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();

                if ( commandHandler.isValidCommand(commandInput) )
                {
                    std::string sortByTitleString;
                    bool sortByTitle;

                    switch ( commandInput )
                    {
                        case 1 :
                            commandHandler.clearConsole();
                            std::cout << "Sort by title? (y/n): ";
                            TrekStar::Information::listProjects(projects, TrekStar::Command::GetBoolInput());
                            break;
                        case 2 :
                            TrekStar::Information::searchProjects(projects);
                            break;
                        default :
                            break;
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
