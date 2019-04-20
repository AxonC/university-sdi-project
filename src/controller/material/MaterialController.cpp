#include "MaterialController.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialController::MaterialController(MaterialInterface & model, ViewInterface & view)
        {
            this->model = &model;
            this->view = &view;
        }

        void MaterialController::SetModel(MaterialInterface* & model)
        {
            this->model = model;
        }

        void MaterialController::SetView(ConsoleMessageView* & view)
        {
            this->view = view;
        }

        void MaterialController::ShowAll()
        {
            this->view->Present();
        }
    }
}