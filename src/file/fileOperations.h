#ifndef TREKSTAR_FILEOPERATIONS_H
#define TREKSTAR_FILEOPERATIONS_H

#include <fstream>
#include <vector>

#include "../model/project/Project.h"
#include "../model/material/Material.h"
#include "../model/material/MaterialFactory.h"

using ProjectVector = std::vector<TrekStar::Project::Project>;
using MaterialVector = std::vector<std::shared_ptr<TrekStar::Material::Material>>;
using CrewVector = std::vector<std::shared_ptr<TrekStar::People::Crew>>;

namespace TrekStar
{
    namespace File
    {
        TrekStar::Project::Project createProject(const json &);

        MaterialVector createMaterials(const json &);

        ProjectVector importProjects(const std::string &);
    }
}

#endif //TREKSTAR_FILEOPERATIONS_H
