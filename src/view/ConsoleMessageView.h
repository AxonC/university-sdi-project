#ifndef TREKSTAR_CONSOLEMESSAGEVIEW_H
#define TREKSTAR_CONSOLEMESSAGEVIEW_H

#include <string>
#include "../Model.h"
#include "../controller/Controller.h"

namespace TrekStar
{
    namespace View
    {
        class ConsoleMessageView
        {
        public:
            ConsoleMessageView() = default;
            ConsoleMessageView(Model* &, Controller* &);
            ~ConsoleMessageView() = default;

            virtual void Present() = 0;

            void SetModel(Model* &);
            void SetController(Controller* &);

            virtual Model* GetModel() = 0;
        protected:
            Model* model;
            Controller* controller;
        };
    }
}

#endif //TREKSTAR_CONSOLEMESSAGEVIEW_H