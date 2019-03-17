//
// Created by Matt Robinson on 2019-03-16.
//

#include "fileOperations.h"

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

std::vector<TrekStar::Project::Project> importProjects(std::string fileDirectory, std::vector<std::string> files)
{
    TrekStar::Project::Project currentProject;
    std::vector<TrekStar::Project::Project> projects;

    for (std::vector<std::string>::iterator it = files.begin() ; it != files.end(); ++it) {
        if (*it != "." && *it != "..")
        {
            std::ifstream dataFile (fileDirectory + "/" + *it);

            if ( ! isFileOpen(dataFile) || ! isFileOkay(dataFile) )
            {
                if ( ! isFileOpen(dataFile) )
                {
                    std::cout << "Error: File not found." << std::endl;
                }
                if ( ! isFileOkay(dataFile) )
                {
                    std::cout << "Error: There was an error reading the file, it may be corrupted." << std::endl;
                }
            }
            else
            {
                currentProject = TrekStar::Project::Project(dataFile);
                projects.push_back(currentProject);
            }
        }
    }
}