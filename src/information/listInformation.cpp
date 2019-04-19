#include <vector>
#include <map>
#include <iostream>

#include "listInformation.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"

using TrekStar::Project::Project;
using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;
using TrekStar::Material::Material;
using TrekStar::Material::MaterialController;
using TrekStar::Material::MaterialView;

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
            for ( auto &project: projects )
            {
                ProjectView view(project);
                ProjectController controller(project, view);

                controller.ListProjects();
            }
        }


        /**
            Prints to standard output the materials for a given project.

            @param vector of projects.
            @param integer containing the project number.
        */
        void listMaterials(std::vector<TrekStar::Project::Project> projects, int projectNum)
        {
            std::vector<std::shared_ptr<TrekStar::Material::Material>> materials = projects[projectNum - 1].GetMaterials();

            std::string userInput;
            unsigned int currentMaterial = 0;
            bool error = false;

            while ( userInput != "b" )
            {
                if ( !error )
                {
                    const auto material = materials.at(currentMaterial);
                    MaterialView view = MaterialView(*material);
                    MaterialController controller(material, view);
                    controller.ShowAll();
                }

                std::cout << std::string(80, '-') << std::endl;
                std::cout << "n - next material, p - previous material, b - go back" << std::endl;
                std::cout << std::string(80, '-') << std::endl;
                std::cout << "> ";
                std::cin >> userInput;

                if ( userInput == "n" )
                {
                    if ( currentMaterial + 1 == materials.size() )
                    {
                        std::cout << "No more materials to show..." << std::endl;
                        error = true;
                    }
                    else
                    {
                        error = false;
                        currentMaterial++;
                    }
                }
                else if ( userInput == "p" )
                {
                    if ( currentMaterial < 1 )
                    {
                        std::cout << "No previous materials to show..." << std::endl;
                        error = true;
                    }
                    else
                    {
                        error = false;
                        currentMaterial--;
                    }
                }
                else
                {
                    break;
                }
            }
        }
    }
}