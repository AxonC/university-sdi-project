#ifndef TREKSTAR_PROJECTINTERFACE_H
#define TREKSTAR_PROJECTINTERFACE_H

#include <string>

#include "../Model.h"

namespace TrekStar
{
    namespace Project
    {
        class ProjectInterface : public Model
        {
        public:
            virtual ~ProjectInterface() = default;
            virtual unsigned int GetId() const = 0;
            virtual std::string GetTitle() const = 0;
            virtual std::string GetSummary() const = 0;
            virtual bool GetReleased() const = 0;
            virtual bool GetPlayingInTheatres() const = 0;
        };
    }
}

#endif //TREKSTAR_PROJECTINTERFACE_H
