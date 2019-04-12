#include "DoubleSideDVD.h"

namespace TrekStar {
    namespace Material {
        DoubleSideDVD::DoubleSideDVD(unsigned int id, const std::string &name) : DVD(id, name)
        {

        }

        void DoubleSideDVD::PopulateFromFile(const json & j)
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
    }
}

