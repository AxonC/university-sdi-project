#ifndef SDI_PROJECT_LISTINFORMATION_H
#define SDI_PROJECT_LISTINFORMATION_H

#include <iostream>

#include "../model/material/DVD.h"
#include "../model/project/Project.h"
#include "../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void listProjects(std::vector<TrekStar::Project::Project> projects);

        void listMaterials(std::vector<TrekStar::Project::Project> projects, int projectNum);
    }
}

#endif //SDI_PROJECT_LISTINFORMATION_H
