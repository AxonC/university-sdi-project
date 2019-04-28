#ifndef TREKSTAR_CREWCONTROLLER_H
#define TREKSTAR_CREWCONTROLLER_H

#include "../../view/people/CrewView.h"
#include "../../model/people/CrewInterface.h"
#include "../BaseController.h"

namespace TrekStar
{
    namespace People
    {
        class CrewController : public BaseController
        {
        public:
            CrewController() = default;
            CrewController(CrewInterface & model, ViewInterface & view);
            ~CrewController() = default;

            void Update();
            void AddNew();

        private:
            CrewInterface* GetModel();
            CrewView* GetView();

            void UpdateName();
            void UpdateJobTitle();
        };
    }
}

#endif //TREKSTAR_CREWCONTROLLER_H
