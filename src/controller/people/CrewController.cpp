#include "CrewController.h"

namespace TrekStar
{
    namespace People
    {
        CrewController::CrewController(CrewInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void CrewController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();

            switch ( commandInput )
            {
            case 1:
                this->UpdateName();
                break;
            case 2:
                this->UpdateJobTitle();
                break;
            default:
                break;
            }
        }

        void CrewController::AddNew()
        {
            this->UpdateName();
            this->UpdateJobTitle();
        }

        CrewInterface* CrewController::GetModel()
        {
            return dynamic_cast<CrewInterface*>(this->model);
        }

        CrewView* CrewController::GetView()
        {
            return dynamic_cast<CrewView*>(this->view);
        }

        void CrewController::UpdateName()
        {
            this->GetModel()->SetName(this->GetView()->GetNewName());
        }

        void CrewController::UpdateJobTitle()
        {
            this->GetModel()->SetJobTitle(this->GetView()->GetNewJobTitle());
        }
    }
}