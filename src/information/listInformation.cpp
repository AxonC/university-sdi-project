#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

#include "listInformation.h"
#include "SequentialBrowser.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/BinarySearch.h"
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
        void listProjects(std::vector<TrekStar::Project::Project> & projects)
        {
            std::string userInput;
            int currentProject = 0;

            TrekStar::Algorithms::mergeSort(projects);

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


        void searchProjects(std::vector<TrekStar::Project::Project> & projects, std::string searchCriteria)
        {
            TrekStar::Algorithms::mergeSort(projects);

            std::transform(searchCriteria.begin(), searchCriteria.end(), searchCriteria.begin(), ::tolower);
            unsigned int projectIndex = TrekStar::Algorithms::binarySearch(projects, searchCriteria);

            if ( projectIndex == -1 )
            {
                std::cout << "'" << searchCriteria << "' could not be found..." << std::endl;
            }
            else
            {
                ProjectView view(projects.at(projectIndex));
                ProjectController controller(projects.at(projectIndex), view);
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