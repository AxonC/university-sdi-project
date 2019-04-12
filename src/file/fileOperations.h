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

using MaterialVector = std::vector<std::shared_ptr<TrekStar::Material::Material>>;

namespace TrekStar {
    namespace File {
        bool isFileOpen(std::ifstream& file);

        bool isFileOkay(std::ifstream& file);

        std::vector<std::string> readDirectory(const std::string&);

        std::vector<TrekStar::Project::Project> importProjects(std::vector<std::string> files);
    }
}

#endif //TREKSTAR_FILEOPERATIONS_H
