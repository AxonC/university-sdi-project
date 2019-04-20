#include "BaseView.h"

namespace TrekStar
{
    namespace View
    {
        BaseView::BaseView(Model* & model, ControllerInterface* & controller)
        {
            this->model = model;
            this->controller = controller;
        }

        void BaseView::SetController(ControllerInterface* & controller)
        {
            this->controller = controller;
        }

        void BaseView::SetModel(Model* & model)
        {
            this->model = model;
        }
    }
}