#ifndef TREKSTAR_DOUBLESIDEDVD_H
#define TREKSTAR_DOUBLESIDEDVD_H

#include "DVD.h"

namespace TrekStar
{
    namespace Material
    {
        struct SerialisedDoubleSideDVD
        {
            explicit SerialisedDoubleSideDVD(const SerialisedMaterial & baseMaterial, const std::vector<SerialisedDVDSide> & sides)
            {
                this->sides = sides;
                this->material = baseMaterial;
            }
            SerialisedMaterial material;
            std::vector<SerialisedDVDSide> sides;
        };

        class DoubleSideDVD: public DVD
        {
        protected:
            DVDSide sideTwo;

        public:
          DoubleSideDVD() = default;

          void PopulateFromFile(const json &) override;

          std::vector<DVDSide> GetSides() const;
          KeyValueMapVector GetPresentableDiskInformation() const;

          std::shared_ptr<SerialisedDoubleSideDVD> ExportToSerialised() const;
        };

        void to_json(json & j, const SerialisedDoubleSideDVD & serialisedDoubleSideDVD);
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H