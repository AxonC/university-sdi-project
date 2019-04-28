#ifndef SDI_PROJECT_COMMANDHANDLER_H
#define SDI_PROJECT_COMMANDHANDLER_H

using IntegerStringMap = std::map<int, std::string>;

namespace TrekStar
{
    namespace Command
    {
        class CommandHandler
        {
        public:
            CommandHandler() = default;
            CommandHandler(const IntegerStringMap & commands, const std::string & currentAction);

            bool isValidCommand(const int & command) const;
            void displayCommands() const;
            void clearConsole() const;
            int getUserInput() const;

        private:
            IntegerStringMap commands;
            std::string currentAction;
        };
    }
}

#endif //SDI_PROJECT_COMMANDHANDLER_H
