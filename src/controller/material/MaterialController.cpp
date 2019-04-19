#include "MaterialController.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialController::MaterialController(const std::shared_ptr<Material> & model, const MaterialView & view)
        {
            this->SetModel(model);
            this->SetView(view);
        }

        void MaterialController::SetModel(const std::shared_ptr<Material> & model)
        {
            this->model = model;
            //this->model = std::make_shared<Material>(model);
        }

        void MaterialController::SetView(const MaterialView & view)
        {
            this->view = view;
        }

        void MaterialController::ShowAll()
        {
            this->view.Present();
        }
    }
}