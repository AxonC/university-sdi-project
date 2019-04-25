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

            virtual std::string GetName() const = 0;
            virtual std::string GetJobTitle() const = 0;

            virtual void SetName(const std::string & name) = 0;
            virtual void SetJobTitle(const std::string & title) = 0;
        };
    }
}

#endif //TREKSTAR_CREWINTERFACE_H
