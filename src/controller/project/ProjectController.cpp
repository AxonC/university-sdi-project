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

        void ProjectController::UpdateProject()
        {
            unsigned int commandInput = this->GetView()->GetProjectUpdateOption();

            switch ( commandInput )
            {
            case 1:
                this->UpdateTitle();
                break;
            case 2:
                this->UpdateSummary();
                break;
            case 3:
                this->UpdateReleased();
                break;
            case 4:
                this->UpdatePlayingInTheatres();
                break;
            case 5:
                this->UpdateKeyword();
                break;
            default:
                break;
            }
        }

        void ProjectController::UpdateAll()
        {
            this->UpdateTitle();
            this->UpdateSummary();
            this->UpdateReleased();
            this->UpdatePlayingInTheatres();
        }

        void ProjectController::UpdateMaterials()
        {
            this->GetView()->PresentMaterialsList();
        }

        void ProjectController::UpdateTitle()
        {
            this->GetModel()->SetTitle(this->GetView()->GetNewTitle());
        }

        void ProjectController::UpdateSummary()
        {
            this->GetModel()->SetSummary(this->GetView()->GetNewSummary());
        }

        void ProjectController::UpdateReleased()
        {
            this->GetModel()->SetReleased(this->GetView()->GetNewReleased());
        }

        void ProjectController::UpdatePlayingInTheatres()
        {
            this->GetModel()->SetPlayingInTheatres(this->GetView()->GetNewPlayingInTheatres());
        }

        void ProjectController::UpdateKeyword()
        {
            this->GetView()->PresentKeywords();

            unsigned int keywordNo = this->GetView()->GetKeywordNo();
            this->GetModel()->SetKeyword(keywordNo, this->GetView()->GetNewKeyword(keywordNo));
        }

        ProjectInterface* ProjectController::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }

        ProjectView* ProjectController::GetView()
        {
            return dynamic_cast<ProjectView*>(this->view);
        }
    }
}
