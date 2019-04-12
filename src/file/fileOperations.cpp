#include <iostream>

#include "fileOperations.h"
#include "boost/filesystem.hpp"
#include "../material/BoxSet.h"
#include "../lib/json.hpp"

using json = nlohmann::json;

namespace TrekStar {
    namespace File {
        bool isFileOpen(std::ifstream& file)
        {
            return file.is_open();
        }

        bool isFileOkay(std::ifstream& file)
        {
            return file.good();
        }

        // Returns a sorted vector of filename entries in a directory (given as parameter).
        std::vector<std::string> readDirectory(const std::string& path)
        {
            std::vector<std::string> result;

            boost::filesystem::path p (path);
            boost::filesystem::directory_iterator end_itr;

            // cycle through the directory
            for (boost::filesystem::directory_iterator itr(p); itr != end_itr; ++itr)
            {
                // If it's not a directory, list it. If you want to list directories too, just remove this check.
                if (is_regular_file(itr->path())) {
                    // assign current file name to current_file and echo it out to the console.
                    std::string current_file = itr->path().string();

                    result.push_back(current_file);
                }
            }

            return result;
        }

        TrekStar::Project::Project createProject(const json & jsonString)
        {
            TrekStar::Project::SerialisedProject serialised;
            try {
                serialised = jsonString.get<TrekStar::Project::SerialisedProject>();
            } catch (json::out_of_range & ) {
                // TODO: Conceputalise exception logic
            }

            return TrekStar::Project::Project(serialised);
        }

        std::vector<std::shared_ptr<Material::Material>> createMaterials(std::ifstream& dataFile)
        {
            dataFile.clear();                  // clear fail and eof bits
            dataFile.seekg(0, std::ios::beg);  // go back to the start

            std::vector<std::shared_ptr<Material::Material>> materials;
            std::shared_ptr<Material::Material> currentMaterial;
            std::vector<std::string> materialAttributes;
            std::string line;

            while (getline(dataFile, line))
            {
                if (line[0] != '#' && !line.empty())
                {
                    std::string::size_type pos = line.find('|');
                    if (line.substr(0, pos) == "Material")
                    {
                        while (pos != std::string::npos)
                        {
                            pos = line.find('|');
                            materialAttributes.push_back(line.substr(0, pos));
                            line = line.substr(pos + 1);
                        }

                        currentMaterial = Material::MaterialFactory::Create(materialAttributes.at(3));

                        if ( currentMaterial != nullptr ) {
                            currentMaterial->PopulateFromFile(materialAttributes);

                            materials.push_back(currentMaterial);
                        }
                    }
                }
            }

            dataFile.close();

            return materials;
        }

        MaterialVector createMaterials(const json & jsonString)
        {
            MaterialVector materials;
            std::shared_ptr<Material::Material> currentMaterial;
            std::string format;

            for (auto && value: jsonString) {
                std::vector<std::string> object;
                format = value.at("format");

                currentMaterial = Material::MaterialFactory::Create(format);

                if (currentMaterial != nullptr) {
                    // TODO: Add serializable stuff to Materials
                    currentMaterial->PopulateFromFile(value);
                    materials.push_back(currentMaterial);
                } else {
                    throw std::domain_error("Material format is not supported.");
                }
            }

            return materials;
        }

        std::vector<TrekStar::Project::Project> importProjects(std::vector<std::string> files)
        {
            TrekStar::Project::Project currentProject;
            std::shared_ptr<Material::Material> currentMaterial;
            std::vector<TrekStar::Project::Project> projects;

            std::ifstream dataFile(files.at(0));
            json jsonStream = json::parse(dataFile);

            for (auto &it : jsonStream) {
                // ensure that there is a key called details
                if (it.find("details") != it.end())
                {
                    currentProject = createProject(it.at("details"));
                }

                if (it.find("materials") != it.end())
                {
                    currentProject.AddMaterials(createMaterials(it.at("materials")));
                }

                projects.push_back(currentProject);
            }

//            for (std::vector<std::string>::iterator it = files.begin() ; it != files.end(); ++it)
//            {
//                if (*it != "." && *it != "..")
//                {
//                    std::ifstream dataFile (*it);
//
//                    if ( ! isFileOpen(dataFile) || ! isFileOkay(dataFile) )
//                    {
//
//                        if ( ! isFileOpen(dataFile) )
//                        {
//                            std::cout << "Error: File not found." << std::endl;
//                        }
//                        if ( ! isFileOkay(dataFile) )
//                        {
//                            std::cout << "Error: There was an error reading the file, it may be corrupted." << std::endl;
//                        }
//                    }
//                    else
//                    {
//                        currentProject = createProject(dataFile);
//
//                        try
//                        {
//                            currentProject.AddMaterials(createMaterials(dataFile));
//                            projects.push_back(currentProject);
//                        }
//                        catch (std::domain_error ex)
//                        {
//                            break;
//                        }
//                    }
//                }
//            }

            return projects;
        }
    }
}


