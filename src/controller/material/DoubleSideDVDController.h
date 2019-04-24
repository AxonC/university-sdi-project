#ifndef TREKSTAR_DOUBLESIDEDVDCONTROLLER_H
#define TREKSTAR_DOUBLESIDEDVDCONTROLLER_H

#include "MaterialController.h"
#include "../../view/material/DoubleSideDVDView.h"
#include "../../model/material/DoubleSideDVD.h"
#include "../../model/material/DoubleSideDVDInterface.h"

namespace TrekStar
{
    namespace Material
    {
        class DoubleSideDVDController : public MaterialController
        {
        private:
            void UpdateSideOneContent();
            void UpdateSideOneAdditionalLanguageTracks();
            void UpdateSideOneAdditionalSubtitleTracks();
            void UpdateSideOneBonusFeatures();
            void UpdateSideTwoContent();
            void UpdateSideTwoAdditionalLanguageTracks();
            void UpdateSideTwoAdditionalSubtitleTracks();
            void UpdateSideTwoBonusFeatures();

            DoubleSideDVDView* GetView() override;
            DoubleSideDVD* GetModel() override;

        public:
            DoubleSideDVDController(DoubleSideDVD & model, DoubleSideDVDView & view);

            void Update() override;
        };
    }
}

#endif //TREKSTAR_DOUBLESIDEDVDCONTROLLER_H
