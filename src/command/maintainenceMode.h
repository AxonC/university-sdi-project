#ifndef TREKSTAR_MAINTAINENCEMODE_H
#define TREKSTAR_MAINTAINENCEMODE_H

#include "../information/addInformation.h"

namespace TrekStar
    {
    namespace Command
    {
        void maintainenceMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects);
    }
}

#endif //TREKSTAR_MAINTAINENCEMODE_H
