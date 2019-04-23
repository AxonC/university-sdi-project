#include <iostream>

#include "command/CommandHandler.h"
#include "command/viewMode.h"
#include "command/maintenanceMode.h"
#include "file/fileOperations.h"

int main()
{
	const std::string FILE_PATH = "../data/data.json";
    auto logger = spdlog::daily_logger_mt("logger", "../logs/changes.txt", 23, 59);

    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects(FILE_PATH);

    std::cout << "Welcome to TrekStar Management System | Console" << std::endl;
    std::cout << std::endl;
    std::cout << "Type 'help' to see all available commands" << std::endl;

    TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
            {
                    {1, "view mode"},
                    {2, "maintenance mode"},
                    {3, "quit"}
            },
            "Main Menu"
    );

    int commandInput = 0;
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
                TrekStar::Command::maintenanceMode(FILE_PATH, projects);
                break;
            default :
                break;
        }
    }

    return 0;
}
