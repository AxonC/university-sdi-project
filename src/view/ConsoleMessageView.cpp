#include "ConsoleMessageView.h"

namespace TrekStar
{
    namespace View
    {
        ConsoleMessageView::ConsoleMessageView(Model* & model, ControllerInterface* & controller)
        {
            this->model = model;
            this->controller = controller;
        }

        void ConsoleMessageView::SetController(ControllerInterface* & controller)
        {
            this->controller = controller;
        }

        void ConsoleMessageView::SetModel(Model* & model)
        {
            this->model = model;
        }
    }
}