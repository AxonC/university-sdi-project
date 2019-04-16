#ifndef SDI_PROJECT_LISTINFORMATION_H
#define SDI_PROJECT_LISTINFORMATION_H

#include <iostream>

#include "../material/DVD/DVD.h"
#include "../project/Project.h"
#include "../material/BoxSet/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void listProjects(std::vector<TrekStar::Project::Project> projects);

        void listMaterials(std::vector<TrekStar::Project::Project> projects, int projectNum);
    }
}

#endif //SDI_PROJECT_LISTINFORMATION_H
