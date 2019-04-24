#ifndef TREKSTAR_UPDATEINFORMATION_H
#define TREKSTAR_UPDATEINFORMATION_H

#include "../model/project/Project.h"

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<TrekStar::Project::Project> & projects, int projectIndex);

        void updateMaterials(std::vector<TrekStar::Project::Project> & projects, int projectIndex);
    }
}

#endif //TREKSTAR_UPDATEINFORMATION_H
