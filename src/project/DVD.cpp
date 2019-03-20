//
// Created by Matt Robinson on 2019-03-15.
//

#include "DVD.h"

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar DVD Class Implementation
         */
        std::vector<std::string> DVD :: GetAdditionalLanguageTracks() const
        {
            return additionalLanguageTracks;
        }

        std::vector<std::string> DVD :: GetAdditionalSubtitleTracks() const
        {
            return additionalSubtitleTracks;
        }

        std::vector<std::string> DVD :: GetBonusFeatures() const
        {
            return bonusFeatures;
        }

        DVD::DVD() : Material()
        {

        }
    }
}