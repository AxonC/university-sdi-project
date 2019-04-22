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
#include "../command/CommandHandler.h"

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
        void displayAllProjects(std::vector<TrekStar::Project::Project> & projects)
        {
            for ( auto & project: projects )
            {
                ProjectView view(project);
                ProjectController controller(project, view);
                controller.ShowList();
            }
        }

        /**
            Prints to standard output the projects.

            @param vector of projects.
        */
        void listProjects(std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "next project"},
                            {2, "previous project"},
                            {3, "go back"}
                    },
                    "List Projects"
            );

            TrekStar::Algorithms::mergeSort(projects);

            int commandInput = 0;
            int currentProject = 0;

            while ( commandInput != 3 )
            {
                SequentialBrowser sequentialBrowser(projects.size(), currentProject, commandInput);

                currentProject = sequentialBrowser.GetItemNumber();

                ProjectView view(projects.at(currentProject));
                ProjectController controller(projects.at(currentProject), view);
                controller.ShowAll();

                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();
            }
        }


        void searchProjects(std::vector<TrekStar::Project::Project> & projects)
        {
            std::string searchCriteria;
            std::cout << "Project title: ";
            std::cin >> searchCriteria;

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
                controller.ShowAll();
            }
        }


        /**
            Prints to standard output the materials for a given project.

            @param vector of projects.
            @param integer containing the project number.
        */
        void listMaterials(std::vector<TrekStar::Project::Project> projects, int projectNum)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "next material"},
                            {2, "previous material"},
                            {3, "go back"}
                    },
                    "List Materials"
            );

            std::vector<std::shared_ptr<TrekStar::Material::Material>> materials = projects[projectNum - 1].GetMaterials();

            int commandInput = 0;
            int currentMaterial = 0;

            while ( commandInput != 3 )
            {
                SequentialBrowser sequentialBrowser(materials.size(), currentMaterial, commandInput);

                currentMaterial = sequentialBrowser.GetItemNumber();

                const auto material = materials.at(currentMaterial);
                MaterialView view = MaterialView(*material);
                MaterialController controller(*material, view);
                controller.ShowAll();

                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();
            }
        }
    }
}