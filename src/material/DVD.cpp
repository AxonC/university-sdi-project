#include "DVD.h"
#include <iostream>

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

        SerialisedDVDSide DVD::ExportToSerialised() const
        {
            return this->sideOne.ExportToSerialised();
        }

        void DVD::PopulateFromFile(const json & j)
        {
            this->format = j.at("format");
            this->audioFormat = j.at("audioFormat");
            this->runTime = j.at("runTime").get<int>();
            this->language = j.at("language");
            this->retailPrice = j.at("retailPrice").get<double>();
            this->subtitles = j.at("subtitles");
            this->frameAspect = j.at("frameAspect");

            json additionalLanguageTracksJSON = j.at("additionalLanguageTracks");
            std::vector<std::string> additionalLanguageTracks;

            for (auto &it : additionalLanguageTracksJSON) {
                additionalLanguageTracks.push_back(it);
            }

            json additionalSubtitleTracksJSON = j.at("additionalSubtitleTracks");
            std::vector<std::string> additionalSubtitleTracks;

            for (auto &it : additionalSubtitleTracksJSON) {
                additionalSubtitleTracks.push_back(it);
            }

            json bonusFeaturesJSON = j.at("bonusFeatures");
            std::vector<std::string> bonusFeatures;

            for (auto &it : bonusFeaturesJSON) {
                bonusFeatures.push_back(it);
            }

            this->sideOne = DVDSide(j.at("content"), additionalLanguageTracks, additionalSubtitleTracks, bonusFeatures);
        }

        KeyValueMap DVD::GetPresentableInformation() const
        {
            // call the base class function to get the basic details.
            KeyValueMap information = Material::GetPresentableInformation();

            KeyValueMap sideOne = this->sideOne.GetPresentableInformation();
            information.insert(sideOne.begin(), sideOne.end());

            return information;
        }

        json to_json(const SerialisedDVDSide & dvd, const std::shared_ptr<Material> & materialObject)
        {
            json j = TrekStar::Material::to_json(materialObject->ExportToSerialised());

            j["content"] = dvd.content;
            j["additionalLanguageTracks"] = dvd.additionalLanguageTracks;
            j["additionalSubtitleTracks"] = dvd.additionalSubtitleTracks;
            j["bonusFeatures"] = dvd.bonusFeatures;

            return j;
        }
    }
}