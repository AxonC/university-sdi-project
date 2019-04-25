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
        };
    }
}

#endif //TREKSTAR_CREWVIEW_H
