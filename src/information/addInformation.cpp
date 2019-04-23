#include <iostream>

#include "addInformation.h"
#include "../view/project/ProjectView.h"
#include "../controller/project/ProjectController.h"

using TrekStar::Project::Project;
using TrekStar::Project::ProjectController;
using TrekStar::Project::ProjectView;

namespace TrekStar
{
    namespace Information
    {
        void addProject(std::vector<TrekStar::Project::Project> & projects)
        {
            TrekStar::Project::Project currentProject;

            ProjectView view(currentProject);
            ProjectController controller = ProjectController(currentProject, view);

            controller.UpdateAll();

            projects.push_back(currentProject);
        }
    }
}