#ifndef TREKSTAR_VHSCONTROLLER_H
#define TREKSTAR_VHSCONTROLLER_H

#include "MaterialController.h"
#include "../../view/material/VHSView.h"
#include "../../model/material/VHS.h"

namespace TrekStar
{
    namespace Material
    {
        class VHSController : public MaterialController
        {
        public:
            VHSController(VHS & model, VHSView & view);

            void Update() override;
            void AddNew() override;

        private:
            void UpdateAudioTrack();
            void UpdatePackaging();

            VHSView* GetView() override;
            VHS* GetModel() override;
        };
    }
}

#endif //TREKSTAR_VHSCONTROLLER_H
