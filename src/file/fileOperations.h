//
// Created by Matt Robinson on 2019-03-16.
//

#ifndef TREKSTAR_FILEOPERATIONS_H
#define TREKSTAR_FILEOPERATIONS_H

#include <fstream>
#include <vector>

bool isFileOpen(std::ifstream & file);

bool isFileOkay(std::ifstream & file);

std::vector<std::string> read_directory(const std::string& path = std::string());

#endif //TREKSTAR_FILEOPERATIONS_H
