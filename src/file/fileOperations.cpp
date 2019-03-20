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

TrekStar::Project::Project createProject(std::ifstream& dataFile)
{
    TrekStar::Project::Project aProject;
    std::vector<std::string> projectAttributes;
    std::string line;

    while (getline(dataFile, line))
    {
        if (line[0] != '#')
        {
            std::string::size_type pos = line.find('|');
            if (line.substr(0, pos) == "Project")
            {
                while (pos != std::string::npos)
                {
                    pos = line.find('|');
                    projectAttributes.push_back(line.substr(0, pos));
                    line = line.substr(pos + 1);
                }
            }
        }
    }

    std::string title = projectAttributes[1];
    std::string summary = projectAttributes[2];

    bool released;

    if (projectAttributes[3] == "true")
    {
        released = true;
    }
    else
    {
        released = false;
    }

    bool playingInTheatres;

    if (projectAttributes[4] == "true")
    {
        playingInTheatres = true;
    }
    else
    {
        playingInTheatres = false;
    }

    aProject = TrekStar::Project::Project(title, summary, released, playingInTheatres);

    return aProject;
}

std::vector<std::shared_ptr<Material::Material>> createMaterials(std::ifstream& dataFile)
{
    std::vector<std::shared_ptr<Material::Material>> materials;
    std::shared_ptr<Material::Material> currentMaterial;
    std::vector<std::string> materialAttributes;
    std::string line;

    while (getline(dataFile, line))
    {
        if (line[0] != '#')
        {
            std::string::size_type pos = line.find('|');
            if (line.substr(0, pos) == "Material")
            {
                std::string id = static_cast<unsigned int>(std::stoi(materialAttributes[0]));
                std::string title = materialAttributes[1];
                std::string format = materialAttributes[2];
                std::string audioFormat = materialAttributes[3];
                std::string runTime = materialAttributes[4];
                std::string language = materialAttributes[5];
                unsigned long int retailPrice = std::stoul(materialAttributes[6], nullptr ,0);
                std::string subtitles = materialAttributes[7];
                std::string frameAspect = materialAttributes[8];

                currentMaterial = Material::MaterialFactory::Create(format);

                currentMeterial->populateFromFile(id, title, format, audioFormat, runTime, language, retailPrice, subtitles, frameAspect);

                projectMaterials.push_back(currentMaterial);
            }
        }
    }
}

std::vector<TrekStar::Project::Project> importProjects(std::string fileDirectory, std::vector<std::string> files)
{
    TrekStar::Project::Project currentProject;
    std::shared_ptr<Material::Material> currentMaterial;
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
                currentProject = createProject(dataFile);
                currentMaterial = Material::MaterialFactory::Create(
                projects.push_back(currentProject);
            }
        }
    }

    return projects;
}