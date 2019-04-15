#ifndef TREKSTAR_DOUBLESIDEDVD_H
#define TREKSTAR_DOUBLESIDEDVD_H

#include "DVD.h"

namespace TrekStar {
    namespace Material {

        struct SerialisedDoubleSideDVD: virtual SerialisedMaterial {
            explicit SerialisedDoubleSideDVD(const SerialisedMaterial & baseMaterial, const std::vector<SerialisedDVDSide> & sides)
            : SerialisedMaterial(baseMaterial) {
                this->sides = sides;
            }
            std::vector<SerialisedDVDSide> sides;
        };

        class DoubleSideDVD: public DVD {
        protected:
            DVDSide sideTwo;
        public:
          DoubleSideDVD() = default;
          DoubleSideDVD(unsigned int id, const std::string & name);

          KeyValueMapVector GetPresentableDiskInformation() const;
          std::shared_ptr<SerialisedMaterial> ExportToSerialised() const override;
          void PopulateFromFile(const json &) override;
        };

        void to_json(const std::vector<SerialisedDVDSide> & sides, const std::shared_ptr<Material> & materialObject);
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H
