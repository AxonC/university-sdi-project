#ifndef TREKSTAR_FILEOPERATIONS_H
#define TREKSTAR_FILEOPERATIONS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <dirent.h>
#include <sys/types.h>

#include "../project/Project.h"
#include "../material/Material.h"
#include "../material/MaterialFactory.h"

using ProjectVector = std::vector<TrekStar::Project::Project>;
using MaterialVector = std::vector<std::shared_ptr<TrekStar::Material::Material>>;

namespace TrekStar {
    namespace File {
        TrekStar::Project::Project createProject(const json &);

        MaterialVector createMaterials(const json &);

        ProjectVector importProjects(std::vector<std::string>);
    }
}

#endif //TREKSTAR_FILEOPERATIONS_H
