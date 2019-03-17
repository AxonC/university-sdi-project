//
// Created by Matt Robinson on 2019-03-16.
//

#include "fileOperations.h"

#include <dirent.h>
#include <sys/types.h>

bool isFileOpen(std::ifstream& file)
{
    return file.is_open();
}

bool isFileOkay(std::ifstream& file)
{
    return file.good();
}

// Returns a sorted vector of filename entries in a directory (given as parameter).
std::vector<std::string> readDirectory(const std::string& path = std::string())
{
    std::vector<std::string> result;
    dirent* de;
    DIR* dp;
    errno = 0;

    dp = opendir(path.empty() ? "." : path.c_str());
    if (dp) {
        while (true) {
            errno = 0;
            de = readdir(dp);

            if (de == NULL) {
                break;
            }

            result.push_back(std::string(de->d_name));
        }

        closedir(dp);
        std::sort(result.begin(), result.end());
    }
    return result;
}

#include <iostream>
std::vector<TrekStar::Project::Project> importProjects(std::vector<std::string> files)
{
    for (std::vector<std::string>::iterator it = files.begin() ; it != files.end(); ++it) {
        std::cout << *it << std::endl;
    }
}