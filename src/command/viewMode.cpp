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
                            {"lsp",  "list projects"},
                            {"sp",   "<criteria> search projects"},
                            {"lsm",  "<project id> list materials"},
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
                    if ( tokenisedCommand.first == "lsp" )
                    {
                        TrekStar::Information::listProjects(projects);
                    }
                    else if ( tokenisedCommand.first == "sp" )
                    {
                        TrekStar::Information::searchProjects(projects, tokenisedCommand.second);
                    }
                    else if ( tokenisedCommand.first == "lsm" )
                    {
                        try
                        {
                            TrekStar::Information::listMaterials(projects, commandHandler.getIntegerValue(tokenisedCommand.second));
                        }
                        catch ( std::invalid_argument )
                        {
                            std::cout << "Invalid parameter, please try again." << std::endl;
                        }
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