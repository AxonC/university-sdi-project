//
// Created by Matt Robinson on 2019-03-15.
//

#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include <vector>
#include <string>

namespace TrekStar {
    namespace Material {
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

            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;
        };
    }
}

#endif //TREKSTAR_DVD_H
