#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include <vector>
#include <string>
#include "Material.h"
#include "DVDSide.h"


using TrekStar::Material::Material;

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar DVD Class
         */
        class DVD : public Material
        {
        private:
            DVDSide sideOne;
        public:
            DVD();
            DVD(unsigned int id, const std::string & title);

            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;
            void PopulateFromFile(const std::vector<std::string> &) override;
        };
    }
}

#endif //TREKSTAR_DVD_H
