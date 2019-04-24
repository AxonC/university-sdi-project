#include "DVD.h"

namespace TrekStar
{
    namespace Material
    {
        /**
         *  Trekstar DVD Class Implementation
         */
        DVD::DVD() : Material() {}

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

            for ( auto &it : additionalLanguageTracksJSON )
            {
                additionalLanguageTracks.push_back(it);
            }

            json additionalSubtitleTracksJSON = j.at("additionalSubtitleTracks");
            std::vector<std::string> additionalSubtitleTracks;

            for ( auto &it : additionalSubtitleTracksJSON )
            {
                additionalSubtitleTracks.push_back(it);
            }

            json bonusFeaturesJSON = j.at("bonusFeatures");
            std::vector<std::string> bonusFeatures;

            for ( auto &it : bonusFeaturesJSON )
            {
                bonusFeatures.push_back(it);
            }

            this->sideOne = DVDSide(j.at("content"), additionalLanguageTracks, additionalSubtitleTracks, bonusFeatures);
        }

        std::string DVD::GetContent() const
        {
            return this->sideOne.GetContent();
        }

        std::vector<std::string> DVD::GetAdditionalLanguageTracks() const
        {
            return this->sideOne.GetAdditionalLanguageTracks();
        }

        std::vector<std::string> DVD::GetAdditionalSubtitleTracks() const
        {
            return this->sideOne.GetAdditionalSubtitleTracks();
        }

        std::vector<std::string> DVD::GetBonusFeatures() const
        {
            return this->sideOne.GetBonusFeatures();
        }

        DVDSide DVD::GetSide() const
        {
            return this->sideOne;
        }

        KeyValueMap DVD::GetPresentableInformation() const
        {
            // call the base class function to get the basic details.
            KeyValueMap information = Material::GetPresentableInformation();

            KeyValueMap sideOne = this->sideOne.GetPresentableInformation();
            information.insert(sideOne.begin(), sideOne.end());

            return information;
        }

        void DVD::SetAdditionalLanguageTracks(const std::vector<std::string> & additionalLanguageTracks)
        {
            this->sideOne.SetAdditionalLanguageTracks(additionalLanguageTracks);
        }

        void DVD::SetAdditionalSubtitleTracks(const std::vector<std::string> & additionalSubtitleTracks)
        {
            this->sideOne.SetAdditionalSubtitleTracks(additionalSubtitleTracks);
        }

        void DVD::SetBonusFeatures(const std::vector<std::string> & bonusFeatures)
        {
            this->sideOne.SetBonusFeatures(bonusFeatures);
        }

        void DVD::SetContent(const std::string & content)
        {
            this->sideOne.SetContent(content);
        }

        void DVD::SetAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack)
        {
            this->sideOne.SetAdditionalLanguageTrack(index, languageTrack);
        }

        void DVD::SetAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack)
        {
            this->sideOne.SetAdditionalSubtitleTrack(index, subtitleTrack);
        }

        void DVD::SetBonusFeature(unsigned int index, const std::string & bonusFeature)
        {
            this->sideOne.SetBonusFeature(index, bonusFeature);
        }

        std::shared_ptr<SerialisedDVD> DVD::ExportToSerialised() const
        {
            std::shared_ptr<SerialisedMaterial> serialisedMaterial = Material::ExportToSerialised();

            SerialisedDVD doubleSideDVD(*serialisedMaterial, this->sideOne.ExportToSerialised());

            return std::make_shared<SerialisedDVD>(doubleSideDVD);
        }

        void to_json(json & j, const SerialisedDVD & dvd)
        {
            j["id"] = dvd.material.id;
            j["format"] = dvd.material.format;
            j["audioFormat"] = dvd.material.audioFormat;
            j["runTime"] = dvd.material.runTime;
            j["language"] = dvd.material.language;
            j["retailPrice"] = dvd.material.retailPrice;
            j["subtitles"] = dvd.material.subtitles;
            j["frameAspect"] = dvd.material.frameAspect;

            j["content"] = dvd.sideOne.content;
            j["additionalLanguageTracks"] = dvd.sideOne.additionalLanguageTracks;
            j["additionalSubtitleTracks"] = dvd.sideOne.additionalSubtitleTracks;
            j["bonusFeatures"] = dvd.sideOne.bonusFeatures;
        }
    }
}