#include "fileOperations.h"
#include "../material/BoxSet/BoxSet.h"
#include "../lib/json.hpp"
#include <iostream>

using json = nlohmann::json;

namespace TrekStar
{
    namespace File
    {
        /**
            Creates a new project.

            @param json string containing serialised data for a single project.
            @return object containing the created project.
        */
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


        /**
            Creates a number of materials.

            @param json string containing serialised data for multiple material.
            @return vector of created materials.
        */
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


        /**
            Creates a new of crew.

            @param json string containing serialised data for multiple crew.
            @return vector of created crew.
        */
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


        /**
            Obtains project information from a file.

            @param string containing the file path of the JSON file.
            @return a vector of projects obtained from the JSON file.
        */
        ProjectVector importProjects(const std::string & filePath)
        {
            TrekStar::Project::Project currentProject;
            std::shared_ptr<Material::Material> currentMaterial;
            ProjectVector projects;

            std::ifstream dataFile(filePath);
			json jsonStream;
			try {
				jsonStream = json::parse(dataFile);
			}
			catch (json::parse_error &e)
			{
				std::cerr << e.what() << std::endl;
			}

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
