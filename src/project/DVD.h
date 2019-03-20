//
// Created by Matt Robinson on 2019-03-15.
//

#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include <vector>
#include <string>
#include "Material.h"

using TrekStar::Material::Material;

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar DVD Class
         */
        class DVD : public Material
        {
        private:
            std::string content;                                // DVD contents
            std::vector<std::string> additionalLanguageTracks;  // other languages available
            std::vector<std::string> additionalSubtitleTracks;  // any additional subtitles
            std::vector<std::string> bonusFeatures;             // for short films or directors comments
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
