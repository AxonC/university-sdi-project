#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "project/Project.h"
#include "material/Material.h"

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

        currentProjectJSON["details"] = TrekStar::Project::to_json(projects.at(0).ExportToSerialised());

        toWriteJSON[std::to_string(counter)] = currentProjectJSON;
    }

    json materialArray;
    for (const auto & m: projects.at(0).GetMaterials())
    {
        materialArray.push_back(TrekStar::Material::to_json(m->ExportToSerialised()));
    }

    toWriteJSON["materials"] = materialArray;

    std::ofstream JSONfile(filePath);
    JSONfile << std::setw(4) << toWriteJSON << std::endl;
    JSONfile.close();
}