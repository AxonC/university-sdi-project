#include <iostream>

#include "CommandHandler.h"

namespace TrekStar
{
    namespace Command
    {
        CommandHandler::CommandHandler(const StringMap & commands)
        {
            this->commands = commands;
        }

        bool CommandHandler::isValidCommand(const std::string & command) const
        {
            return this->commands.find(command) != this->commands.end();
        }

        StringPair CommandHandler::tokeniseCommand(const std::string & command) const
        {
            std::string::size_type pos = command.find(' ');

            return std::make_pair<std::string, std::string>(command.substr(0, pos), command.substr(pos + 1));
        }

        int CommandHandler::getIntegerValue(const std::string & commandOpcode) const
        {
            return std::stoi(commandOpcode);
        }

        void CommandHandler::displayCommands() const
        {
            std::cout << std::string(80,'-') << std::endl;
            for ( const auto & currentCommand : this->commands )
            {
                std::cout << currentCommand.first << " - " << currentCommand.second << ", ";
            }
            std::cout << std::endl << std::string(80,'-') << std::endl;
        };
    }
}