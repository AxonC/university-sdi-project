#include "DVDSide.h"

namespace TrekStar {
    namespace Material {
        std::vector<std::string> tokeniseString(std::string theString, char token)
        {
            std::vector<std::string> tokenisedString;

            std::string::size_type pos = theString.find(token);
            while (pos != std::string::npos)
            {
                pos = theString.find(token);
                tokenisedString.push_back(theString.substr(0, pos));
                theString = theString.substr(pos + 1);
            }

            return tokenisedString;
        }

        DVDSide::DVDSide(std::string additionalLanguageTracks, std::string additionalSubtitleTracks, std::string bonusFeatures)
        {
            this->additionalLanguageTracks = tokeniseString(additionalLanguageTracks, ',');
            this->additionalSubtitleTracks = tokeniseString(additionalSubtitleTracks, ',');
            this->bonusFeatures = tokeniseString(bonusFeatures, ',');
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
