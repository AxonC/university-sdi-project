#ifndef TREKSTAR_USERINPUT_H
#define TREKSTAR_USERINPUT_H

#include <vector>
#include <string>

namespace TrekStar
{
    namespace Command
    {
        std::string GetStringInput();
        bool GetBoolInput();
        int GetIntInput();
        std::vector<std::string> GetStringVectorInput(unsigned int noOfElements, std::string name);
        unsigned int GetIndexInput(unsigned int vectorSize, const std::string & name);
    }
}

#endif //TREKSTAR_USERINPUT_H
