#include <iostream>
#include "DVDSide.h"

namespace TrekStar {
    namespace Material {
        DVDSide::DVDSide(std::string additionalLanguageTracks, std::string additionalSubtitleTracks, std::string bonusFeatures)
        {
            std::cout << additionalLanguageTracks << std::endl;
            std::cout << additionalSubtitleTracks << std::endl;
            std::cout << bonusFeatures << std::endl;
        }

        std::vector<std::string> DVDSide::GetAdditionalLanguageTracks() const
        {
            return this->additionalLanguageTracks;
        }

        std::vector<std::string> DVDSide::GetAdditionalSubtitleTracks() const
        {
            return this->additionalSubtitleTracks;
        }

        std::vector<std::string> DVDSide::GetBonusFeatures() const
        {
            return this->bonusFeatures;
        }
    }
}
