#ifndef TREKSTAR_USERINPUT_H
#define TREKSTAR_USERINPUT_H

#include <string>

namespace TrekStar
{
    namespace Command
    {
        std::string GetStringInput();
        bool GetBoolInput();
        int GetIntInput();
    }
}

#endif //TREKSTAR_USERINPUT_H
