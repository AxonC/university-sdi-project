#ifndef TREKSTAR_SINGLESIDEDVD_H
#define TREKSTAR_SINGLESIDEDVD_H

#include "DVD.h"

namespace TrekStar {
    namespace Material {
        class SingleSideDVD: public DVD {
         public:
            SingleSideDVD() = default;
            SingleSideDVD(unsigned int id, const std::string & name);

            void PopulateFromFile(const std::vector<std::string> &) override;
        };
    }
}

#endif //TREKSTAR_SINGLESIDEDVD_H