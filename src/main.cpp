#include <iostream>

#include "command/CommandHandler.h"
#include "command/viewMode.h"
#include "command/maintainenceMode.h"
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
                    {"v", "view mode"},
                    {"m", "maintainence mode"},
                    {"q", "quit"}
            }
    );

    std::string commandInput;
    while ( commandInput != "q" && commandInput != "quit" )
    {
        commandHandler.displayCommands();
        std::cout << std::endl;
        std::cout << "> ";
        std::getline(std::cin, commandInput);

        if ( commandInput == "v" )
        {
            TrekStar::Command::viewMode(FILE_PATH, projects);
        }
        else if ( commandInput == "m" )
        {
            TrekStar::Command::maintainenceMode(FILE_PATH, projects);
        }
    }

    return 0;
}
