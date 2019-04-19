#ifndef SDI_PROJECT_BLURAY_H
#define SDI_PROJECT_BLURAY_H

#include "DVD.h"

namespace TrekStar
{
    namespace Material
    {
        struct SerialisedBluray
        {
            explicit SerialisedBluray(const SerialisedMaterial & baseMaterial, const SerialisedDVDSide & dvdSide)
            {
              this->sideOne = dvdSide;
              this->material = baseMaterial;
            }

            SerialisedDVDSide sideOne;
            SerialisedMaterial material;
        };

        class Bluray : public DVD
        {
            private:

            public:
                Bluray();

                std::shared_ptr<SerialisedBluray> ExportToSerialised() const;
        };

        void to_json(json & j, const SerialisedBluray & dvd);
    }
}

#endif //SDI_PROJECT_BLURAY_H
