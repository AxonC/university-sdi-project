#include "pch.h"
#include "CommandHandler.h"

namespace TrekStar
{
    namespace Command
    {
        /**
          Class:                 CommandHandler
          Method Name:           CommandHandler (constructor)
          Method Access Control: Public

          Constructs the CommandHandler.

          @param A map of integers and strings containing the commands and their respective user input values.
          @param A string containing the current action being taken by the user.
        */
        CommandHandler::CommandHandler(const IntegerStringMap & commands, const std::string & currentAction)
        {
            this->commands = commands;
            this->currentAction = currentAction;
        }


        /**
            Class:                 CommandHandler
            Method Name:           isValidCommand
            Method Access Control: Public

            Responsible for checking that the user's input constitutes a valid command.

            @param An integer containing the user's input selection.
            @return True if the user's input is valid
        */
        bool CommandHandler::isValidCommand(const int & command) const
        {
            return this->commands.find(command) != this->commands.end();
        }


        /**
            Class:                 CommandHandler
            Method Name:           displayCommands
            Method Access Control: Public

            Responsible for printing to standard output the available commands.
        */
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


        /**
            Class:                 CommandHandler
            Method Name:           clearConsole
            Method Access Control: Public

            Responsible for printing to standard output so that the console is "cleared".
        */
        void CommandHandler::clearConsole() const
        {
            for ( int i = 0; i < 100; i++ )
            {
                std::cout << '\n';
            }
        }


        /**
            Class:                 CommandHandler
            Method Name:           getUserInput
            Method Access Control: Public

            Responsible for obtaining input from the user and performing validation.

            @return An integer containing the user's selection.
        */
        int CommandHandler::getUserInput() const
        {
            bool validCommand = false;
            int commandInput = 0;

            while ( !validCommand )
            {
                std::cout << "> ";
                std::cin >> commandInput;

                // If the command was valid and there were no errors with the input stream.
                if ( !std::cin.fail() && isValidCommand(commandInput) )
                {
                    validCommand = true;
                }
                else
                {
                    std::cout << "Invalid command..." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(256,'\n');
                }
            }

            return commandInput;
        }
    }
}