#ifndef SDI_PROJECT_LISTINFORMATION_H
#define SDI_PROJECT_LISTINFORMATION_H

#include "../material/DVD.h"
#include "../project/Project.h"
#include "../material/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void listProjects(std::vector<TrekStar::Project::Project> projects);

        void listMaterials(std::vector<TrekStar::Project::Project> projects, std::string projectNumString);
    }
}

#endif //SDI_PROJECT_LISTINFORMATION_H
