#ifndef TREKSTAR_DOUBLESIDEDVD_H
#define TREKSTAR_DOUBLESIDEDVD_H

#include "DVD.h"

namespace TrekStar {
    namespace Material {
        class DoubleSideDVD: public DVD {
        protected:
            DVDSide sideTwo;
        public:
          DoubleSideDVD() = default;
          DoubleSideDVD(unsigned int id, const std::string & name);

          KeyValueMap GetPresentableInformation() const override;
          std::vector<SerialisedDVDSide> ExportToSerialised() const;
          void PopulateFromFile(const json &) override;
        };

        json to_json(const std::vector<SerialisedDVDSide> & sides, const std::shared_ptr<Material> & materialObject);
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H
