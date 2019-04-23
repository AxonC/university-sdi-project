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

            int commandInput = 0;
            while ( commandInput != 4 )
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
                            sortByTitleString;
                            sortByTitle = false;
                            std::cout << "Sort by title? (y/n): ";
                            std::cin >> sortByTitleString;
                            commandHandler.clearConsole();

                            if ( sortByTitleString == "y" )
                            {
                                sortByTitle = true;
                            }

                            TrekStar::Information::listProjects(projects, sortByTitle);
                            break;
                        case 2 :
                            TrekStar::Information::searchProjects(projects);
                            break;
                        case 3 :
                            try
                            {
                                std::cout << std::string(80, '-') << std::endl;
                                TrekStar::Information::displayAllProjects(projects);
                                std::cout << std::string(80, '-') << std::endl;

                                int projectID;
                                std::cout << "Project ID: ";
                                std::cin >> projectID;
                                commandHandler.clearConsole();

                                TrekStar::Information::listMaterials(projects, projectID);
                            }
                            catch ( std::invalid_argument & )
                            {
                                std::cout << "Invalid parameter, please try again." << std::endl;
                            }
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
