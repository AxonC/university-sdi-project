#include <iostream>

#include "command/CommandHandler.h"
#include "command/viewMode.h"
#include "command/maintainenceMode.h"
#include "file/fileOperations.h"

int main()
{
	const std::string FILE_PATH = "../data/data.json";

    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects(FILE_PATH);

    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;
    std::cout << std::endl;
    std::cout << "Type 'help' to see all available commands" << std::endl;

    TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
            {
                    {1, "view mode"},
                    {2, "maintainence mode"},
                    {3, "quit"}
            },
            "Main Menu"
    );

    int commandInput;
    while ( commandInput != 3 )
    {
        commandHandler.displayCommands();
        commandInput = commandHandler.getUserInput();
        commandHandler.clearConsole();

        switch ( commandInput )
        {
            case 1 :
                TrekStar::Command::viewMode(FILE_PATH, projects);
                break;
            case 2 :
                TrekStar::Command::maintainenceMode(FILE_PATH, projects);
                break;
            default :
                std::cout << "Invalid command..." << std::endl;
        }
    }

    return 0;
}
