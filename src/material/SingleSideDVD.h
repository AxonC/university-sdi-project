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
            SingleSideDVD(unsigned int id, const std::string & name);

            void PopulateFromFile(const json &) override;
        };
    }
}

#endif //TREKSTAR_SINGLESIDEDVD_H