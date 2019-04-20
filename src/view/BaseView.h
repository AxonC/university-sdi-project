#ifndef TREKSTAR_BASEVIEW_H
#define TREKSTAR_BASEVIEW_H

#include <string>
#include "../model/Model.h"
#include "../controller/ControllerInterface.h"
#include "ViewInterface.h"

using TrekStar::Controller::ControllerInterface;
using TrekStar::View::ViewInterface;

namespace TrekStar
{
    namespace View
    {
        class BaseView: public ViewInterface
        {
        protected:
            Model* model;
            ControllerInterface* controller;

        public:
            BaseView() = default;
            BaseView(Model* &, ControllerInterface* &);
            ~BaseView() = default;

            virtual void SetModel(Model* &);
            virtual void SetController(ControllerInterface* &);

            virtual Model* GetModel() = 0;
        };
    }
}

#endif //TREKSTAR_BASEVIEW_H