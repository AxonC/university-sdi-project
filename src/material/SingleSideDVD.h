#ifndef TREKSTAR_SINGLESIDEDVD_H
#define TREKSTAR_SINGLESIDEDVD_H

#include "DVD.h"

namespace TrekStar
{
    namespace Material
    {
        class SingleSideDVD: public DVD {
        public:
            SingleSideDVD() = default;

            void PopulateFromFile(const json &) override;
        };
    }
}

#endif //TREKSTAR_SINGLESIDEDVD_H