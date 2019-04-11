#ifndef TREKSTAR_DVDSIDE_H
#define TREKSTAR_DVDSIDE_H

#include "DVD.h"

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
        };
    }
}


#endif //TREKSTAR_DVDSIDE_H
