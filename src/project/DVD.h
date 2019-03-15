//
// Created by Matt Robinson on 2019-03-15.
//

#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include <vector>
#include <string>

namespace TrekStar {
    namespace DVD {
        /**
         *  Trekstar DVD Class
         */
        class DVD
        {
        private:
            std::vector<std::string> additionalLanguageTracks;
            std::vector<std::string> additionalSubtitleTracks;
            std::vector<std::string> bonusFeatures;  // for short films or directors comments
        public:
            DVD();
            ~DVD();

            std::vector<std::string> getAdditionalLanguageTracks();
            std::vector<std::string> getAdditionalSubtitleTracks();
            std::vector<std::string> getBonusFeatures();
        };
    }
}

#endif //TREKSTAR_DVD_H
