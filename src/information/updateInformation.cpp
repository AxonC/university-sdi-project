#include <iostream>

#include "updateInformation.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"
#include "../command/CommandHandler.h"

using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;
using TrekStar::Material::MaterialController;
using TrekStar::Material::MaterialView;

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<TrekStar::Project::Project> & projects, int projectID)
        {
            TrekStar::Project::Project currentProject = projects.at(projectID);

            ProjectView view(currentProject);
            ProjectController controller(currentProject, view);
            controller.UpdateProject();
        }

        void updateMaterials(std::vector<TrekStar::Project::Project> & projects, int projectID)
        {
            TrekStar::Project::Project currentProject = projects.at(projectID);

            ProjectView view(currentProject);
            ProjectController controller(currentProject, view);
            controller.UpdateMaterials();
        }
    }
}
