#include <iostream>

#include "CommandHandler.h"

namespace TrekStar
{
    namespace Command
    {
        CommandHandler::CommandHandler(const std::map<std::string, std::string> & commands)
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

        std::map<std::string, std::string> CommandHandler::GetCommands() const
        {
            return this->commands;
        }

        void CommandHandler::displayCommands() const
        {
            for ( const auto & currentCommand : this->commands )
            {
                std::cout << currentCommand.first << " - " << currentCommand.second << std::endl;
            }
        };
    }
}