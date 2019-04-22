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
                            {"addp", "<title> add project"},
                            {"save", "save changes to file"},
                            {"b",    "go back"}
                    }
            );

            std::string commandInput;
            while ( commandInput != "b" )
            {
                commandHandler.displayCommands();
                std::cout << std::endl;
                std::cout << "> ";
                std::getline(std::cin, commandInput);

                StringPair tokenisedCommand = commandHandler.tokeniseCommand(commandInput);

                if ( commandHandler.isValidCommand(tokenisedCommand.first) )
                {
                    if ( tokenisedCommand.first == "addp" )
                    {
                        TrekStar::Information::addProject(projects);
                    }
                    else if ( tokenisedCommand.first == "save" )
                    {
                        TrekStar::Information::save(projects, FILE_PATH);
                    }
                }
                else
                {
                    std::cout << "'" << tokenisedCommand.first << "'" << " is not a valid command. Type 'help' to see all available commands." << std::endl;
                }
            }
        }
    }
}