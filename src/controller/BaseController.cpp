#include "BaseController.h"

namespace TrekStar
{
    BaseController::BaseController(Model* & model, ConsoleMessageView* & view)
    {
        this->model = model;
        this->view = view;
    }

    void BaseController::SetModel(Model* & model)
    {
        this->model = model;
    }

    void BaseController::SetView(ConsoleMessageView* & view)
    {
        this->view = view;
    }
}