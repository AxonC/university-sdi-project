#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "project/Project.h"
#include "material/Material.h"
#include "material/DVD.h"
#include "material/DoubleSideDVD.h"

#include "lib/json.hpp"
using json = nlohmann::json;

void save(std::vector<TrekStar::Project::Project> projects, std::string filePath)
{
    json toWriteJSON;

    int counter = 0;
    for(const auto & project: projects)
    {
        counter++;
        json currentProjectJSON;

        currentProjectJSON["details"] = TrekStar::Project::to_json(project.ExportToSerialised());

        toWriteJSON[std::to_string(counter)] = currentProjectJSON;


        json materialArray;
        for (const auto & m: project.GetMaterials())
        {
            if( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(m) )
            {
                materialArray.push_back(TrekStar::Material::to_json(materialType->ExportToSerialised(), m));
            }
            else if( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(m) )
            {
                materialArray.push_back(TrekStar::Material::to_json(materialType->ExportToSerialised(), m));
            }
            else
            {
                materialArray.push_back(TrekStar::Material::to_json(m->ExportToSerialised()));
            }
        }

        currentProjectJSON["materials"] = materialArray;

        json crewArray;
        for (const auto & crew: project.GetCrew())
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