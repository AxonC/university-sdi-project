#ifndef TREKSTAR_BASECONTROLLER_H
#define TREKSTAR_BASECONTROLLER_H

#include "ControllerInterface.h"
#include "../model/Model.h"
#include "../view/ConsoleMessageView.h"

using TrekStar::View::ConsoleMessageView;

namespace TrekStar
{
    class BaseController : public ControllerInterface
    {
    protected:
        Model* model;
        ConsoleMessageView* view;

    public:
        BaseController() = default;
        BaseController(Model* & model, ConsoleMessageView* & view);
        ~BaseController() = default;

        void SetModel(Model* & model);
        void SetView(ConsoleMessageView* & view);

        virtual void ShowAll() = 0;
    };
}

#endif //TREKSTAR_BASECONTROLLER_H
