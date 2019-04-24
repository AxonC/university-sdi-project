#include "pch.h"
#include "updateInformation.h"

#include "../command/CommandHandler.h"
#include "../model/project/Project.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"
#include "../view/material/MaterialView.h"
#include "../controller/material/MaterialController.h"

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<Project::Project> & projects, int projectID)
        {
            Project::Project currentProject = projects.at(projectID);

            Project::ProjectView view(currentProject);
            Project::ProjectController controller(currentProject, view);
            controller.UpdateProject();
        }

        void updateMaterials(std::vector<Project::Project> & projects, int projectID)
        {
            Project::Project currentProject = projects.at(projectID);

            Project::ProjectView view(currentProject);
            Project::ProjectController controller(currentProject, view);
            controller.UpdateMaterials();
        }
    }
}
