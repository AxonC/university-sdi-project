#ifndef SDI_PROJECT_SAVEINFORMATION_H
#define SDI_PROJECT_SAVEINFORMATION_H

#include "../project/Project.h"
#include "../material/Material/Material.h"
#include "../material/DVD/DVD.h"
#include "../material/DoubleSideDVD/DoubleSideDVD.h"
#include "../material/BoxSet/BoxSet.h"

namespace TrekStar
{
    namespace Information
    {
        void save(std::vector<TrekStar::Project::Project> projects, const std::string & filePath);
    }
}

#endif //SDI_PROJECT_SAVEINFORMATION_H
