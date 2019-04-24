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

        int GetIntInput()
        {
            int input;
            std::cin >> input;
            return input;
        }

        std::vector<std::string> GetStringVectorInput(unsigned int noOfElements, std::string name)
        {
            std::vector<std::string> input;

            std::string inputValue;

            for ( int i = 0; i < noOfElements; i++ )
            {
                std::cout << name << " #" << i + 1 << ": ";
                std::cin.ignore();
                std::getline(std::cin, inputValue);

                input.push_back(inputValue);
            }

            return input;
        }

        unsigned int GetIndexInput(unsigned int vectorSize, const std::string & name)
        {
            if ( vectorSize < 1 )
            {
                return 0;
            }

            unsigned int input = 0;

            while ( input < 1 || input > vectorSize )
            {
                std::cout << name << " [1 - " << vectorSize << "]: ";
                std::cin >> input;
            }

            return input - 1;
        }
    }
}