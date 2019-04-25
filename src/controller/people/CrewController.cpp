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
    }
}