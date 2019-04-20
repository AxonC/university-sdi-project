#include "ProjectController.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectController::ProjectController(ProjectInterface & model, ViewInterface & view)
        {
            this->model = &model;
            this->view = &view;
        }

        void ProjectController::SetModel(ProjectInterface* &model)
        {
            this->model = model;
        }

        void ProjectController::SetView(ConsoleMessageView* & view)
        {
            this->view = view;
        }

        void ProjectController::ListProjects()
        {
            this->view->Present();
        }
    }
}
