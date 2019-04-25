#ifndef TREKSTAR_CREWVIEW_H
#define TREKSTAR_CREWVIEW_H

#include "../BaseView.h"
#include "../../model/people/Crew.h"

using TrekStar::View::BaseView;

namespace TrekStar
{
    namespace People
    {
        class CrewView : public BaseView
        {
        public:
            CrewView() = default;
            explicit CrewView(CrewInterface & model);

            void PresentAll() override;
            void PresentList() override;

            std::string GetNewName();
            unsigned int GetJobTitle();

            unsigned int GetUpdateOption();

            CrewInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_CREWVIEW_H
