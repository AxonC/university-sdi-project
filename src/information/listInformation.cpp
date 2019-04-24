#include "pch.h"

#include "listInformation.h"
#include "SequentialBrowser.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/BinarySearch.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"
#include "../command/CommandHandler.h"
#include "../command/userInput.h"

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
            unsigned int counter = 0;
            for ( auto & project: projects )
            {
                counter++;
                std::cout << "[" << counter << "]: ";
                ProjectView view(project);
                ProjectController controller(project, view);
                controller.ShowList();
            }
        }


        /**
            Prints to standard output the projects.

            @param vector of projects.
        */
        void listProjects(std::vector<TrekStar::Project::Project> & projects, bool sortByTitle)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Next Project"},
                            {2, "Previous Project"},
                            {3, "Cancel"}
                    },
                    "List Projects"
            );

            if ( sortByTitle )
            {
                TrekStar::Algorithms::mergeSort(projects);
            }

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
            std::cout << "Title: ";
            std::string searchCriteria = TrekStar::Command::GetStringInput();

            TrekStar::Algorithms::mergeSort(projects);

            searchCriteria.erase(remove_if(searchCriteria.begin(), searchCriteria.end(), isspace), searchCriteria.end());
            std::transform(searchCriteria.begin(), searchCriteria.end(), searchCriteria.begin(), ::tolower);
            unsigned int projectIndex = TrekStar::Algorithms::binarySearch(projects, searchCriteria);

            if ( projectIndex == -1 )
            {
                std::cout << "Project could not be found..." << std::endl;
            }
            else
            {
                ProjectView view(projects.at(projectIndex));
                ProjectController controller(projects.at(projectIndex), view);
                controller.ShowAll();

                std::cout << "Show materials for this project? (y/n): ";
                if ( TrekStar::Command::GetBoolInput() )
                {
                    listMaterials(projects, projectIndex);
                }
            }
        }


        /**
            Prints to standard output the materials for a given project.

            @param vector of projects.
            @param integer containing the project number.
        */
        void listMaterials(std::vector<TrekStar::Project::Project> & projects, int projectNum)
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Next Material"},
                            {2, "Previous Material"},
                            {3, "Cancel"}
                    },
                    "List Materials"
            );

            std::vector<std::shared_ptr<TrekStar::Material::Material>> materials = projects.at(projectNum).GetMaterials();

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