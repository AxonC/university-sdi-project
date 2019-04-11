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

        void DVD::PopulateFromFile(const std::vector<std::string> & attributes)
        {
            this->id = static_cast<unsigned int>(std::stoi(attributes.at(1)));
            this->title = attributes.at(2);
            this->format = attributes.at(3);
            this->audioFormat = attributes.at(4);
            this->runTime = attributes.at(5);
            this->language = attributes.at(6);
            this->retailPrice = std::stoul(attributes.at(7), nullptr ,0);
            this->subtitles = attributes.at(8);
            this->frameAspect = attributes.at(9);
        }

    }
}