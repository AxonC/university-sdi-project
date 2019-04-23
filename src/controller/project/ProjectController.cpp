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

        void ProjectController::UpdateTitle()
        {
            auto model = dynamic_cast<ProjectInterface*>(this->model);
            model->SetTitle(dynamic_cast<ProjectView*>(this->view)->GetNewTitle());
        }

        void ProjectController::UpdateSummary()
        {
            auto model = dynamic_cast<ProjectInterface*>(this->model);
            model->SetSummary(dynamic_cast<ProjectView*>(this->view)->GetNewSummary());
        }
    }
}
