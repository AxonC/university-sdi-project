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

            void ShowAll() override;
            void ShowList() override;

            void Update();
            void AddNew();

        private:
            void UpdateName();
            void UpdateJobTitle();

            CrewView* GetView();
            CrewInterface* GetModel();
        };
    }
}

#endif //TREKSTAR_CREWCONTROLLER_H
