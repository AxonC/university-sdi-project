#ifndef TREKSTAR_PROJECTINTERFACE_H
#define TREKSTAR_PROJECTINTERFACE_H

#include <string>
#include <vector>

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
            virtual std::vector<std::string> GetKeywords() const = 0;
            virtual std::vector<std::string> GetMaterialFormats() const = 0;

            virtual void SetTitle(const std::string & title) = 0;
            virtual void SetSummary(const std::string & summary) = 0;
            virtual void SetReleased(const bool & released) = 0;
            virtual void SetPlayingInTheatres(const bool & playingInTheatres) = 0;
            virtual void SetKeyword(const unsigned int & keywordNo, const std::string & keyword) = 0;
        };
    }
}

#endif //TREKSTAR_PROJECTINTERFACE_H
