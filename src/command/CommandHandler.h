#ifndef SDI_PROJECT_COMMANDHANDLER_H
#define SDI_PROJECT_COMMANDHANDLER_H

#include <string>
#include <unordered_map>
#include <vector>

using StringMap = std::unordered_map<std::string, std::string>;
using StringPair = std::pair<std::string, std::string>;

namespace TrekStar
{
    namespace Command
    {
        class CommandHandler
        {
        private:
            StringMap commands;
        public:
            CommandHandler() = default;
            explicit CommandHandler(const StringMap & commands);

            bool isValidCommand(const std::string & command) const;
            StringPair tokeniseCommand(const std::string & command) const;
            int getIntegerValue(const std::string & commandOpcode) const;
            void displayCommands() const;
        };
    }
}

#endif //SDI_PROJECT_COMMANDHANDLER_H
