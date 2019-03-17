//
// Created by Matt Robinson on 2019-03-16.
//

#ifndef TREKSTAR_FILEOPERATIONS_H
#define TREKSTAR_FILEOPERATIONS_H

#include "../project/Project.h"
#include <fstream>
#include <vector>

bool isFileOpen(std::ifstream& file);

bool isFileOkay(std::ifstream& file);

std::vector<std::string> readDirectory(const std::string&);

std::vector<TrekStar::Project::Project> importProjects(std::vector<std::string> files);

#endif //TREKSTAR_FILEOPERATIONS_H
