#include "pch.h"
#include "addInformation.h"

#include "../model/project/Project.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"

namespace TrekStar
{
    namespace Information
    {
        void addProject(std::vector<Project::Project> & projects)
        {
            Project::Project currentProject;

            Project::ProjectView view(currentProject);
            Project::ProjectController controller = Project::ProjectController(currentProject, view);

            controller.UpdateAll();

            projects.push_back(currentProject);
        }
    }
}