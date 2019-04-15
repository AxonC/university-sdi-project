#include <map>
#include <string>
#include <fstream>
#include <iomanip>

#include "saveInformation.h"

#include "../lib/json.hpp"

using json = nlohmann::json;

namespace TrekStar
{
    namespace Information
    {
        /**
            Saves the current state of projects/materials to a JSON file.

            @param vector of projects.
            @param file path to JSON output.
        */
        void save(std::vector<TrekStar::Project::Project> projects, const std::string & filePath)
        {
            json toWriteJSON;

            int counter = 0;
            for ( const auto & project: projects )
            {
                counter++;
                json currentProjectJSON;

                auto a = project.ExportToSerialised();

                // gets a serialised version of project and writes it to the json string (returns type SerialisedProject.
                currentProjectJSON["details"] = project.ExportToSerialised();

                toWriteJSON[std::to_string(counter)] = currentProjectJSON;

                json materialArray;
                for ( auto && m: project.GetMaterials() )
                {
                    if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(m) )
                    {
                        // return a SerialisedDoubleSideDVD -> json
                        json j = *materialType->ExportToSerialised();
                        materialArray.push_back(j);
                    }
                    else if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(m) )
                    {
                        json j = *materialType->ExportToSerialised();
                        materialArray.push_back(j);
                    }
                    else if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(m) )
                    {
                        json j = *materialType->ExportToSerialised();
                        materialArray.push_back(j);
                    }
                }

                currentProjectJSON["materials"] = materialArray;

                json crewArray;
                for ( const auto & crew: project.GetCrew() )
                {
                    crewArray.push_back(TrekStar::People::to_json(crew->ExportToSerialized()));
                }

                currentProjectJSON["crew"] = crewArray;

                toWriteJSON[std::to_string(counter)] = currentProjectJSON;
            }

            std::ofstream JSONfile(filePath);
            JSONfile << std::setw(4) << toWriteJSON << std::endl;
            JSONfile.close();
        }
    }
}