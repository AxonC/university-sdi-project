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
            int command;
            std::vector<int> validCommands = {1, 2};
        public:
            SequentialBrowser() = default;
            SequentialBrowser(unsigned int noOfItems, unsigned int currentItem, const int & commandInput);
            ~SequentialBrowser() = default;

            bool isValidCommand();
            unsigned int GetItemNumber();
        };
    }
}

#endif //TREKSTAR_SEQUENTIALBROWSER_H
