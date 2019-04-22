#include <iostream>

#include "CommandHandler.h"

namespace TrekStar
{
    namespace Command
    {
        CommandHandler::CommandHandler(const IntegerStringMap & commands, const std::string & currentAction)
        {
            this->commands = commands;
            this->currentAction = currentAction;
        }

        bool CommandHandler::isValidCommand(const int & command) const
        {
            return this->commands.find(command) != this->commands.end();
        }

        void CommandHandler::displayCommands() const
        {
            std::cout << std::string(80,'-') << std::endl;
            std::cout << this->currentAction << std::endl;
            std::cout << std::string(80,'-') << std::endl;
            for ( const auto & currentCommand : this->commands )
            {
                std::cout << currentCommand.first << " - " << currentCommand.second << std::endl;
            }
            std::cout << std::string(80,'-') << std::endl;
        }

        void CommandHandler::clearConsole() const
        {
            for ( int i = 0; i < 100; i++ )
            {
                std::cout << '\n';
            }
        }

        int CommandHandler::getUserInput() const
        {
            int commandInput;
            std::cout << "> ";
            std::cin >> commandInput;

            return commandInput;
        }
    }
}