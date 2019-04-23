#ifndef TREKSTAR_DVDINTERFACE_H
#define TREKSTAR_DVDINTERFACE_H

#include <string>
#include <map>

#include "MaterialInterface.h"

using KeyValueMap = std::map<std::string, std::string>;

namespace TrekStar
{
    namespace Material
    {
        class DVDInterface
        {
        public:
            virtual ~DVDInterface() = default;

            virtual std::string GetContent() const = 0;

            virtual void SetContent(const std::string & content) = 0;
            virtual void SetAdditionalLanguageTracks(const std::vector<std::string> & additionalLanguageTracks) = 0;
            virtual void SetAdditionalSubtitleTracks(const std::vector<std::string> & additionalSubtitleTracks) = 0;
            virtual void SetBonusFeatures(const std::vector<std::string> & bonusFeatures) = 0;
            virtual void SetAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack) = 0;
            virtual void SetAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack) = 0;
            virtual void SetBonusFeature(unsigned int index, const std::string & bonusFeature) = 0;
        };
    }
}

#endif //TREKSTAR_DVDINTERFACE_H
