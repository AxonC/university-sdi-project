#include "DVDSide.h"

namespace TrekStar {
    namespace Material {
        DVDSide::DVDSide(const std::string & content, StringVector additionalLanguageTracks, StringVector additionalSubtitleTracks, StringVector bonusFeatures)
        {
            this->content = content;
            this->additionalLanguageTracks = additionalLanguageTracks;
            this->additionalSubtitleTracks = additionalSubtitleTracks;
            this->bonusFeatures = bonusFeatures;
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

        KeyValueMap DVDSide::GetPresentableInformation() const
        {
            KeyValueMap information;

            information.insert(std::pair<std::string, std::string>("Content", this->content));

            int counter = 0;
            for(auto & it: this->additionalLanguageTracks)
            {
                counter++;
                information.insert(std::pair<std::string, std::string>("Additional Language Track" + std::to_string(counter), it));
            }

            counter = 0;
            for(auto & it: this->additionalSubtitleTracks)
            {
                counter++;
                information.insert(std::pair<std::string, std::string>("Additional Subtitle Track" + std::to_string(counter), it));
            }

            counter = 0;
            for(auto & it: this->bonusFeatures)
            {
                counter++;
                information.insert(std::pair<std::string, std::string>("Bonus Features" + std::to_string(counter), it));
            }

            return {};
        }
    }
}
