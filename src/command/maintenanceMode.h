#ifndef TREKSTAR_MAINTENANCEMODE_H
#define TREKSTAR_MAINTENANCEMODE_H

#include "../information/addInformation.h"

namespace TrekStar
    {
    namespace Command
    {
        void maintenanceMode(const std::string & FILE_PATH, std::vector<TrekStar::Project::Project> & projects);
    }
}

#endif //TREKSTAR_MAINTENANCEMODE_H
