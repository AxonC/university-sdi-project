#include "pch.h"

#include "listInformation.h"
#include "SequentialBrowser.h"
#include "../algorithms/MergeSort.h"
#include "../algorithms/BinarySearch.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"
#include "../view/people/CrewView.h"
#include "../controller/people/CrewController.h"
#include "../command/CommandHandler.h"
#include "../command/userInput.h"

using TrekStar::Project::Project;
using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;
using TrekStar::Material::Material;
using TrekStar::Material::MaterialController;
using TrekStar::Material::MaterialView;
using TrekStar::People::CrewController;
using TrekStar::People::CrewView;

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
                            {3, "View Materials"},
                            {4, "View Crew"},
                            {5, "Cancel"}
                    },
                    "List Projects"
            );

            if ( sortByTitle )
            {
                TrekStar::Algorithms::mergeSort(projects);
            }

            int commandInput = 0;
            int currentProject = 0;

            while ( commandInput != 5 )
            {
                SequentialBrowser sequentialBrowser(projects.size(), currentProject, commandInput);

                currentProject = sequentialBrowser.GetItemNumber();

                ProjectView view(projects.at(currentProject));
                ProjectController controller(projects.at(currentProject), view);
                controller.ShowAll();

                commandHandler.displayCommands();
                commandInput = commandHandler.getUserInput();
                commandHandler.clearConsole();

                if ( commandInput == 3 )
                {
                    controller.ListMaterials();
                }
                else if ( commandInput == 4 )
                {
                    controller.ListCrew();
                }
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
                    controller.ListMaterials();
                }
            }
        }
    }
}
