#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include <vector>
#include <string>
#include "Material.h"
#include "DVDSide.h"

using TrekStar::Material::Material;

namespace TrekStar {
    namespace Material {
        struct SerialisedDVD
        {
            explicit SerialisedDVD(const SerialisedMaterial & baseMaterial, const SerialisedDVDSide & dvdSide)
            {
                this->sideOne = dvdSide;
                this->material = baseMaterial;
            }
            SerialisedMaterial material;
            SerialisedDVDSide sideOne;
        };

        /**
         *  Trekstar DVD Class
         */
        class DVD : public Material
        {
        protected:
            DVDSide sideOne;
        public:
            DVD();
            DVD(unsigned int id, const std::string & title);

            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;

            std::shared_ptr<SerialisedDVD> ExportToSerialised() const;

            KeyValueMap GetPresentableInformation() const override;
            void PopulateFromFile(const json &) override;
        };

        void to_json(json & j, const SerialisedDVD & dvd);
        void from_json(const json & j, SerialisedDVD & dvd);
    }
}

#endif //TREKSTAR_DVD_H
