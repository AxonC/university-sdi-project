#include "ProjectController.h"

namespace TrekStar
{
    namespace Project
    {
//        ProjectController::ProjectController(Project & model, ProjectView & view)
//        {
//            this->model = model;
//            this->view = view;
//        }

        ProjectController::ProjectController(const Project &model, const ProjectView & view)
        {
            this->SetModel(model);
            this->SetView(view);
        }

        void ProjectController::SetModel(const Project & model)
        {
            this->model = model;
        }

        void ProjectController::SetView(const ProjectView & view)
        {
            this->view = view;
        }

        void ProjectController::ListProjects()
        {
            this->view.Present();
        }
    }
}
