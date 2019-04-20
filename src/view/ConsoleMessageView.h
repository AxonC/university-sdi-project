#ifndef TREKSTAR_CONSOLEMESSAGEVIEW_H
#define TREKSTAR_CONSOLEMESSAGEVIEW_H

#include <string>
#include "../Model.h"
#include "../controller/Controller.h"
#include "ViewInterface.h"

using TrekStar::View::ViewInterface;

namespace TrekStar
{
    namespace View
    {
        class ConsoleMessageView: public ViewInterface
        {
        public:
            ConsoleMessageView() = default;
            ConsoleMessageView(Model* &, Controller* &);
            ~ConsoleMessageView() = default;

            virtual void SetModel(Model* &);
            virtual void SetController(Controller* &);

            virtual Model* GetModel() = 0;
        protected:
            Model* model;
            Controller* controller;
        };
    }
}

#endif //TREKSTAR_CONSOLEMESSAGEVIEW_H