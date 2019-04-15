#ifndef SDI_PROJECT_SAVEINFORMATION_H
#define SDI_PROJECT_SAVEINFORMATION_H

#include "../project/Project.h"
#include "../material/Material.h"
#include "../material/DVD.h"
#include "../material/DoubleSideDVD.h"
#include "../material/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void save(std::vector<TrekStar::Project::Project> projects, const std::string & filePath);
    }
}

#endif //SDI_PROJECT_SAVEINFORMATION_H
