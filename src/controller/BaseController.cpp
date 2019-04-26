#include "BaseController.h"

namespace TrekStar
{
    BaseController::BaseController()
    {
        this->_logger = spdlog::get("logger");
    }

    BaseController::BaseController(Model* & model, ViewInterface* & view) : BaseController()
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