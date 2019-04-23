#include <iostream>

#include "command/CommandHandler.h"
#include "command/viewMode.h"
#include "command/maintenanceMode.h"
#include "information/saveInformation.h"
#include "file/fileOperations.h"

#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"

int main()
{
	const std::string FILE_PATH = "../data/data.json";
    auto logger = spdlog::daily_logger_mt("logger", "../logs/changes.txt", 23, 59);

    std::vector<TrekStar::Project::Project> projects = TrekStar::File::importProjects(FILE_PATH);

    std::cout << std::string(80,'-') << std::endl;
    std::cout << "######## ########  ######## ##    ##  ######  ########    ###    ########  \n"
                 "   ##    ##     ## ##       ##   ##  ##    ##    ##      ## ##   ##     ## \n"
                 "   ##    ##     ## ##       ##  ##   ##          ##     ##   ##  ##     ## \n"
                 "   ##    ########  ######   #####     ######     ##    ##     ## ########  \n"
                 "   ##    ##   ##   ##       ##  ##         ##    ##    ######### ##   ##   \n"
                 "   ##    ##    ##  ##       ##   ##  ##    ##    ##    ##     ## ##    ##  \n"
                 "   ##    ##     ## ######## ##    ##  ######     ##    ##     ## ##     ## \n";
    std::cout << std::string(80,'-') << std::endl << std::endl;

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

    TrekStar::Information::save(projects, FILE_PATH);

    return 0;
}
