#ifndef TREKSTAR_DOUBLESIDEDVDINTERFACE_H
#define TREKSTAR_DOUBLESIDEDVDINTERFACE_H

#include "DVDSide.h"

namespace TrekStar
{
    namespace Material
    {
        class DoubleSideDVDInterface
        {
        public:
            virtual ~DoubleSideDVDInterface() = default;

            virtual DVDSide GetSideOne() const = 0;
            virtual DVDSide GetSideTwo() const = 0;
        };
    }
}

#endif //TREKSTAR_DOUBLESIDEDVDINTERFACE_H
