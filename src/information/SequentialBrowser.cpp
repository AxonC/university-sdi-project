#include "SequentialBrowser.h"
#include <algorithm>
#include <iostream>

namespace TrekStar
{
    namespace Information
    {
        SequentialBrowser::SequentialBrowser(unsigned int noOfItems, unsigned int currentItem, const std::string & command)
        {
            this->noOfItems = noOfItems;
            this->currentItem = currentItem;
            this->command = command;
        }

        bool SequentialBrowser::isValidCommand()
        {
            return std::find(this->validCommands.begin(), this->validCommands.end(), this->command) != this->validCommands.end();
        }

        unsigned int SequentialBrowser::GetItemNumber()
        {
            if ( this->command == "n" )
            {
                if ( this->currentItem + 1 != this->noOfItems )
                {
                    this->currentItem++;
                }
            }
            else if ( this->command == "p" )
            {
                if ( this->currentItem >= 1 )
                {
                    this->currentItem--;
                }
            }

            return this->currentItem;
        }

    }
}