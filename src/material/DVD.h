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
        protected:
            DVDSide sideOne;
        public:
            DVD();
            DVD(unsigned int id, const std::string & title);

            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;

            SerialisedDVDSide ExportToSerialised() const;

            KeyValueMap GetPresentableInformation() const override;
            void PopulateFromFile(const json &) override;
        };

        json to_json(const SerialisedDVDSide & dvd, const std::shared_ptr<Material> & materialObject);
        void from_json(const json & json, SerialisedDVDSide & dvd);
    }
}

#endif //TREKSTAR_DVD_H
