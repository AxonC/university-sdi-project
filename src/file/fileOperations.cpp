#include <iostream>

#include "fileOperations.h"
#include "boost/filesystem.hpp"
#include "../material/BoxSet.h"
#include "../lib/json.hpp"

using json = nlohmann::json;

namespace TrekStar
{
    namespace File
    {
        TrekStar::Project::Project createProject(const json & jsonString)
        {
            TrekStar::Project::SerialisedProject serialised;
            try
            {
                serialised = jsonString.get<TrekStar::Project::SerialisedProject>();
            }
            catch ( json::out_of_range & )
            {
                // TODO: Conceputalise exception logic
            }

            return TrekStar::Project::Project(serialised);
        }

        MaterialVector createMaterials(const json & jsonString)
        {
            MaterialVector materials;
            std::shared_ptr<Material::Material> currentMaterial;
            std::string format;

            for ( auto && value: jsonString )
            {
                std::vector<std::string> object;
                format = value.at("format");

                currentMaterial = Material::MaterialFactory::Create(format);

                if ( currentMaterial != nullptr )
                {
                    currentMaterial->PopulateFromFile(value);
                    materials.push_back(currentMaterial);
                }
                else
                {
                    throw std::domain_error("Material format is not supported.");
                }
            }

            return materials;
        }

        CrewVector createCrew(const json & jsonString)
        {
            CrewVector crewVector;

            for ( auto && item : jsonString )
            {
                std::shared_ptr<TrekStar::People::Crew> newCrew = std::make_shared<Crew>(item.get<TrekStar::People::SerializedCrew>());
                crewVector.push_back(newCrew);
            }

            return crewVector;
        }

        ProjectVector importProjects(std::string filePath)
        {
            TrekStar::Project::Project currentProject;
            std::shared_ptr<Material::Material> currentMaterial;
            ProjectVector projects;

            std::ifstream dataFile(filePath);
            json jsonStream = json::parse(dataFile);

            for ( auto &it : jsonStream)
            {
                // ensure that there is a key called details
                if ( it.find("details") != it.end() )
                {
                    currentProject = createProject(it.at("details"));
                }

                if ( it.find("crew") != it.end() )
                {
                    currentProject.AddCrew(createCrew(it.at("crew")));
                }

                if ( it.find("materials") != it.end() )
                {
                    currentProject.AddMaterials(createMaterials(it.at("materials")));
                }

                projects.push_back(currentProject);
            }

            return projects;
        }
    }
}
