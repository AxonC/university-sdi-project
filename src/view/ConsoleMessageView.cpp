#include "ConsoleMessageView.h"

namespace TrekStar
{
    namespace View
    {
        ConsoleMessageView::ConsoleMessageView(Model* & model, Controller* & controller)
        {
            this->model = model;
            this->controller = controller;
        }

        void ConsoleMessageView::SetController(Controller* & controller)
        {
            this->controller = controller;
        }

        void ConsoleMessageView::SetModel(Model* & model)
        {
            this->model = model;
        }
    }
}