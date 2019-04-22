#include "ProjectController.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectController::ProjectController(ProjectInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void ProjectController::ShowAll()
        {
            this->view->PresentAll();
        }

        void ProjectController::ShowList()
        {
            this->view->PresentList();
        }
    }
}
