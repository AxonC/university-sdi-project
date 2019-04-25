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
        private:
            void UpdateAudioTrack();
            void UpdatePackaging();

            VHSView* GetView() override;
            VHS* GetModel() override;

        public:
            VHSController(VHS & model, VHSView & view);

            void Update() override;
            void AddNew() override;
        };
    }
}

#endif //TREKSTAR_VHSCONTROLLER_H
