#ifndef SDI_PROJECT_SAVEINFORMATION_H
#define SDI_PROJECT_SAVEINFORMATION_H

#include "../model/project/Project.h"
#include "../model/material/Material.h"
#include "../model/material/DVD.h"
#include "../model/material/DoubleSideDVD.h"
#include "../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void save(std::vector<TrekStar::Project::Project> projects, const std::string & filePath);
    }
}

#endif //SDI_PROJECT_SAVEINFORMATION_H
