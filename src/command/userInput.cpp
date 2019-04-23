#include <iostream>

#include "userInput.h"

namespace TrekStar
{
    namespace Command
    {
        std::string GetStringInput()
        {
            std::string input;

            std::cin.ignore();
            std::getline(std::cin, input);

            return input;
        }

        bool GetBoolInput()
        {
            char input;

            do
            {
                std::cin >> input;
            }
            while( !std::cin.fail() && input != 'y' && input != 'n' );

            return input == 'y';
        }
    }
}