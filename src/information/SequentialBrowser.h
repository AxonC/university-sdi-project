#ifndef TREKSTAR_SEQUENTIALBROWSER_H
#define TREKSTAR_SEQUENTIALBROWSER_H

#include <string>
#include <vector>

namespace TrekStar
{
    namespace Information
    {
        class SequentialBrowser
        {
        private:
            unsigned int noOfItems;
            unsigned int currentItem;
            std::string command;
            std::vector<std::string> validCommands = {"n", "p", "b"};
        public:
            SequentialBrowser() = default;
            SequentialBrowser(unsigned int noOfItems, unsigned int currentItem, const std::string & userInput);
            ~SequentialBrowser() = default;

            bool isValidCommand();
            unsigned int GetItemNumber();
        };
    }
}

#endif //TREKSTAR_SEQUENTIALBROWSER_H
