#ifndef TREKSTAR_CREWINTERFACE_H
#define TREKSTAR_CREWINTERFACE_H

#include "../Model.h"

namespace TrekStar
{
    namespace People
    {
        class CrewInterface : public TrekStar::Model
        {
        public:
            ~CrewInterface() override = default;

        };
    }
}

#endif //TREKSTAR_CREWINTERFACE_H
