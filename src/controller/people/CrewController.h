#ifndef TREKSTAR_CREWCONTROLLER_H
#define TREKSTAR_CREWCONTROLLER_H

#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "../../model/people/Crew.h"
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
        };
    }
}

#endif //TREKSTAR_PROJECTCONTROLLER_H


#endif //TREKSTAR_CREWCONTROLLER_H
