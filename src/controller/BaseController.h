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
        ViewInterface* view;

    public:
        BaseController() = default;
        BaseController(Model* &, ViewInterface* &);
        ~BaseController() = default;

        virtual void SetModel(Model* &);
        virtual void SetView(ViewInterface* &);
    };
}

#endif //TREKSTAR_BASECONTROLLER_H
