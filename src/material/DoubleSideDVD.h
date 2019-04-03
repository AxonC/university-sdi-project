#ifndef TREKSTAR_DOUBLESIDEDVD_H
#define TREKSTAR_DOUBLESIDEDVD_H

#include "DVD.h"

namespace TrekStar {
    namespace Material {
        class DoubleSideDVD: public DVD {
         public:
          DoubleSideDVD() = default;
          DoubleSideDVD(unsigned int id, const std::string & name);

          void PopulateFromFile(const std::vector<std::string> &) override;
        };
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H
