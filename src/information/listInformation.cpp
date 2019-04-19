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

            for ( const auto & material: materials )
            {
                MaterialView view = MaterialView(*material);
                MaterialController controller(material, view);

                controller.ShowAll();
            }
        }
    }
}