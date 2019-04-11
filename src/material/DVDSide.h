#ifndef TREKSTAR_DVDSIDE_H
#define TREKSTAR_DVDSIDE_H

#include <string>
#include <vector>

namespace TrekStar {
    namespace Material {
        class DVDSide{
        protected:
            std::string content;                                // DVD contents
            std::vector<std::string> additionalLanguageTracks;  // other languages available
            std::vector<std::string> additionalSubtitleTracks;  // any additional subtitles
            std::vector<std::string> bonusFeatures;             // for short films or directors comments

        public:
            DVDSide() = default;
            DVDSide(std::string additionalLanguageTracks, std::string additionalSubtitleTracks, std::string bonusFeatures);

            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;
        };
    }
}


#endif //TREKSTAR_DVDSIDE_H
