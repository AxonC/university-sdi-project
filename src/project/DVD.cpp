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

        void DVD::PopulateFromFile(const std::vector<std::string> & attributes)
        {
            this->id = static_cast<unsigned int>(std::stoi(attributes.at(0)));
            this->title = attributes.at(1);
            this->format = attributes.at(2);
            this->audioFormat = attributes.at(3);
            this->runTime = attributes.at(4);
            this->language = attributes.at(5);
            this->retailPrice = std::stoul(attributes.at(6), nullptr ,0);
            this->subtitles = attributes.at(7);
            this->frameAspect = attributes.at(8);
        }
        DVD::DVD(unsigned int id, const std::string & title) : Material(id, title)
        {}
    }
}