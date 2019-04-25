#ifndef TREKSTAR_DVDCONTROLLER_H
#define TREKSTAR_DVDCONTROLLER_H

#include "MaterialController.h"
#include "../../view/material/DVDView.h"
#include "../../model/material/DVD.h"
#include "../../model/material/DVDInterface.h"

namespace TrekStar
{
    namespace Material
    {
        class DVDController : public MaterialController
        {
        private:
            void UpdateContent();
            void UpdateAdditionalLanguageTracks();
            void UpdateAdditionalSubtitleTracks();
            void UpdateBonusFeatures();

            void AddAdditionalLanguageTracks();
            void AddAdditionalSubtitleTracks();
            void AddBonusFeatures();

            DVDView* GetView() override;
            DVD* GetModel() override;

        public:
            DVDController(DVD & model, DVDView & view);

            void Update() override;
            void AddNew() override;
        };
    }
}

#endif //TREKSTAR_DVDCONTROLLER_H
