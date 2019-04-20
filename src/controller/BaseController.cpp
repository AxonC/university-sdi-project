#include "BaseController.h"

namespace TrekStar
{
    BaseController::BaseController(Model* & model, ViewInterface* & view)
    {
        this->model = model;
        this->view = view;
    }

    void BaseController::SetModel(Model* & model)
    {
        this->model = model;
    }

    void BaseController::SetView(ViewInterface* & view)
    {
        this->view = view;
    }
}