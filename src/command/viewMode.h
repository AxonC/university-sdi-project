#ifndef TREKSTAR_VIEWMODE_H
#define TREKSTAR_VIEWMODE_H

#include <string>

#include "../information/listInformation.h"

namespace TrekStar
{
    namespace Command
    {
        void viewMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects);
    }
}

#endif //TREKSTAR_VIEWMODE_H
