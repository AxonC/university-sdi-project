#ifndef TREKSTAR_VHSVIEW_H
#define TREKSTAR_VHSVIEW_H

#include "MaterialView.h"
#include "../../model/material/VHS.h"

namespace TrekStar
{
    namespace Material
    {
        class VHSView : public MaterialView
        {
        public:
            explicit VHSView(VHS & model);

            unsigned int GetUpdateOption() override;

            std::string GetNewAudioTrack();
            unsigned int GetNewPackaging();

            void PresentPermittedPackaging();

        private:
            VHS* GetModel() override;
        };
    }
}

#endif //TREKSTAR_VHSVIEW_H
