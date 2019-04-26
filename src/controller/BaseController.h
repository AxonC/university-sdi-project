#ifndef TREKSTAR_BASECONTROLLER_H
#define TREKSTAR_BASECONTROLLER_H

#include "ControllerInterface.h"
#include "../model/Model.h"
#include "../view/BaseView.h"

using TrekStar::View::BaseView;

namespace TrekStar
{
    class BaseController : public ControllerInterface
    {
    protected:
        Model* model;
        ViewInterface* view;
        std::shared_ptr<spdlog::logger> _logger;

    public:
        BaseController();
        BaseController(Model* &, ViewInterface* &);
        ~BaseController() = default;

        virtual void SetModel(Model* &);
        virtual void SetView(ViewInterface* &);
    };
}

#endif //TREKSTAR_BASECONTROLLER_H
