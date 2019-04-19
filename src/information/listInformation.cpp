#include <vector>
#include <map>
#include <iostream>

#include "listInformation.h"
#include "../project/ProjectController.h"
#include "../project/ProjectListView.h"
#include "../material/VHS/VHSController.h"

using TrekStar::Project::Project;
using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectListView;
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
            for ( auto &project: projects )
            {
                // call the list method on the project controller
                // ProjectController(projects)
                // ProjectController.List();
                // ProjectListView -> ConsoleMessageView
                // ProjectListView cout << view.GetMessage()

                // ProjectController(projects)
                // ProjectController.Show(id, const Project)
                // Show { find me the project with the id of 1
                // return me the project view, injecting in that project
                // then just returning that view as a string

                ProjectListView currentProject = ProjectListView(project);
                currentProject.Present();
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