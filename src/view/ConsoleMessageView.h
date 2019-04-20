#ifndef TREKSTAR_CONSOLEMESSAGEVIEW_H
#define TREKSTAR_CONSOLEMESSAGEVIEW_H

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
        class ConsoleMessageView: public ViewInterface
        {
        protected:
            Model* model;
            ControllerInterface* controller;
        public:
            ConsoleMessageView() = default;
            ConsoleMessageView(Model* &, ControllerInterface* &);
            ~ConsoleMessageView() = default;

            virtual void SetModel(Model* &);
            virtual void SetController(ControllerInterface* &);

            virtual Model* GetModel() = 0;
        };
    }
}

#endif //TREKSTAR_CONSOLEMESSAGEVIEW_H