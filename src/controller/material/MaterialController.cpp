#include "MaterialController.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialController::MaterialController(MaterialInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void MaterialController::ShowAll()
        {
            this->view->PresentAll();
        }

        void MaterialController::ShowList()
        {
            this->view->PresentList();
        }

        void MaterialController::Update()
        {
            this->GetView()->GetUpdateOption();
        }

        MaterialView* MaterialController::GetView()
        {
            return dynamic_cast<MaterialView*>(this->view);
        }
    }
}