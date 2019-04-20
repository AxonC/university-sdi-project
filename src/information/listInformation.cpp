#include <vector>
#include <map>
#include <iostream>

#include "listInformation.h"
#include "SequentialBrowser.h"
#include "../algorithms/LinearSearch.h"
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
            std::string userInput;
            int currentProject = 0;

            while ( userInput != "b" )
            {
                SequentialBrowser sequentialBrowser(projects.size(), currentProject, userInput);

                currentProject = sequentialBrowser.GetItemNumber();

                ProjectView view(projects.at(currentProject));
                ProjectController controller(projects.at(currentProject), view);
                controller.ListProjects();

                std::cout << std::string(80, '-') << std::endl;
                std::cout << "n - next project, p - previous project, b - go back" << std::endl;
                std::cout << std::string(80, '-') << std::endl;
                std::cout << "> ";
                std::cin >> userInput;
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
            int currentMaterial = 0;

            while ( userInput != "b" )
            {
                SequentialBrowser sequentialBrowser(materials.size(), currentMaterial, userInput);

                currentMaterial = sequentialBrowser.GetItemNumber();

                const auto material = materials.at(currentMaterial);
                MaterialView view = MaterialView(*material);
                MaterialController controller(material, view);
                controller.ShowAll();

                std::cout << std::string(80, '-') << std::endl;
                std::cout << "n - next material, p - previous material, b - go back" << std::endl;
                std::cout << std::string(80, '-') << std::endl;
                std::cout << "> ";
                std::cin >> userInput;
            }
        }
    }
}