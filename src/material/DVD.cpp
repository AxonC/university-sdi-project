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

        void DVD::PopulateFromFile(const std::vector<std::string> & attributes)
        {
            this->id = static_cast<unsigned int>(std::stoi(attributes.at(1)));
            this->title = attributes.at(2);
            this->format = attributes.at(3);
            this->audioFormat = attributes.at(4);
            this->runTime = attributes.at(5);
            this->language = attributes.at(6);
            this->retailPrice = std::stod(attributes.at(7));
            this->subtitles = attributes.at(8);
            this->frameAspect = attributes.at(9);

            std::string additionalLanguageTracks = attributes.at(10);
            std::string additionalSubtitleTracks = attributes.at(11);
            std::string bonusFeatures = attributes.at(12);

            this->sideOne = DVDSide(additionalLanguageTracks, additionalSubtitleTracks, bonusFeatures);
        }

    }
}