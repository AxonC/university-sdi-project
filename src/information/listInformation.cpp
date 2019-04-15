#include <vector>
#include <map>
#include <iostream>

#include "listInformation.h"

using TrekStar::Project::Project;
using TrekStar::Material::Material;

namespace TrekStar
{
    namespace Information
    {
        /**
            Prints to standard output the projects.

            @param vector of projects.
        */
        void listProjects(std::vector<TrekStar::Project::Project> projects)
        {
            int projectNum = 1;

            for ( const auto &project: projects )
            {
                std::cout << std::string(80, '-') << std::endl;
                std::cout << "Project " << projectNum << std::endl;
                std::cout << std::string(80, '-') << std::endl;

                std::cout << "Title               : " << project.GetTitle() << std::endl;
                std::cout << "Summary             : " << project.GetSummary() << std::endl;
                std::cout << "Released            : " << project.GetReleased() << std::endl;
                std::cout << "Playing in theatres : " << project.GetPlayingInTheatres() << std::endl;
            }
        }


        /**
            Prints to standard output the materials for a given project.

            @param vector of projects.
            @param string containing the project number.
        */
        void listMaterials(std::vector<TrekStar::Project::Project> projects, std::string projectNumString)
        {
            int projectNum = std::stoi(projectNumString);
            std::vector<std::shared_ptr<TrekStar::Material::Material>> materials = projects[projectNum - 1].GetMaterials();

            for ( const auto &material: materials )
            {
                std::cout << std::string(80, '-') << std::endl;
                std::cout << "Material " << material->GetId() << " for Project " << projectNum << std::endl;
                std::cout << std::string(80, '-') << std::endl;

                std::map<std::string, std::string> materialData = material->GetPresentableInformation();

                std::cout << "Title : " << projects.at(projectNum - 1).GetTitle() << std::endl;

                for ( const auto & m : materialData )
                {
                    std::cout << m.first << " : " << m.second << std::endl;
                }

                if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(material) )
                {
                    std::vector<std::map<std::string, std::string>> diskData = materialType->GetPresentableDiskInformation();

                    for ( const auto & d: diskData )
                    {
                        for ( const auto & m: d )
                        {
                            std::cout << m.first << " : " << m.second << std::endl;
                        }
                    }
                }
            }
        }
    }
}