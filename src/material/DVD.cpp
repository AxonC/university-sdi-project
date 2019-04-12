#include "DVD.h"

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar DVD Class Implementation
         */
        DVD::DVD() : Material()
        {}

        DVD::DVD(unsigned int id, const std::string & title) : Material(id, title)
        {}

        std::vector<std::string> DVD :: GetAdditionalLanguageTracks() const
        {
            return this->sideOne.GetAdditionalLanguageTracks();
        }

        std::vector<std::string> DVD :: GetAdditionalSubtitleTracks() const
        {
            return this->sideOne.GetAdditionalSubtitleTracks();
        }

        std::vector<std::string> DVD :: GetBonusFeatures() const
        {
            return this->sideOne.GetBonusFeatures();
        }

        void DVD::PopulateFromFile(const json & j)
        {
            this->id = j.at("id").get<int>();
            this->format = j.at("format");
            this->audioFormat = j.at("audioFormat");
            this->runTime = j.at("runTime").get<int>();
            this->language = j.at("language");
            this->retailPrice = j.at("retailPrice").get<double>();
            this->subtitles = j.at("subtitles");
            this->frameAspect = j.at("frameAspect");

            json additionalLanguageTracksJSON = j.at("additionalLanguageTracks");
            std::vector<std::string> additionalLanguageTracks;

            for (json::iterator it = additionalLanguageTracksJSON.begin(); it != additionalLanguageTracksJSON.end(); ++it) {
                additionalLanguageTracks.push_back(*it);
            }

            json additionalSubtitleTracksJSON = j.at("additionalSubtitleTracks");
            std::vector<std::string> additionalSubtitleTracks;

            for (json::iterator it = additionalSubtitleTracksJSON.begin(); it != additionalSubtitleTracksJSON.end(); ++it) {
                additionalSubtitleTracks.push_back(*it);
            }

            json bonusFeaturesJSON = j.at("bonusFeatures");
            std::vector<std::string> bonusFeatures;

            for (json::iterator it = bonusFeaturesJSON.begin(); it != bonusFeaturesJSON.end(); ++it) {
                bonusFeatures.push_back(*it);
            }

            this->sideOne = DVDSide(additionalLanguageTracks, additionalSubtitleTracks, bonusFeatures);
        }

        KeyValueMap DVD::GetPresentableInformation() const
        {
            // call the base class function to get the basic details.
            KeyValueMap information = Material::GetPresentableInformation();

            int counter = 0;
            for(const auto &additionalLanguageTrack: this->GetAdditionalLanguageTracks())
            {
                counter++;
                information.insert ( std::pair<std::string, std::string>("Additional Language Track #" + std::to_string(counter), additionalLanguageTrack) );
            }

            counter = 0;
            for(const auto &additionalSubtitleTrack: this->GetAdditionalSubtitleTracks())
            {
                counter++;
                information.insert ( std::pair<std::string, std::string>("Additional Subtitle Track #" + std::to_string(counter), additionalSubtitleTrack) );
            }

            counter = 0;
            for(const auto &bonusFeature: this->GetBonusFeatures())
            {
                counter++;
                information.insert ( std::pair<std::string, std::string>("Bonus Feature #" + std::to_string(counter), bonusFeature) );
            }

            return information;
        }

    }
}