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
          void PopulateFromFile(const json &) override;
        };
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H
