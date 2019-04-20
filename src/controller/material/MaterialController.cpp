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
            this->view->Present();
        }
    }
}