//
// Created by Matt Robinson on 2019-03-15.
//

#include "DVD.h"

namespace TrekStar {
    namespace DVD {
        /**
         *  Trekstar DVD Class Implementation
         */
        std::vector<std::string> DVD :: getAdditionalLanguageTracks()
        {
            return additionalLanguageTracks;
        }

        std::vector<std::string> DVD :: getAdditionalSubtitleTracks()
        {
            return additionalSubtitleTracks;
        }

        std::vector<std::string> DVD :: getBonusFeatures()
        {
            return bonusFeatures;
        }
    }
}