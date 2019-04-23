#ifndef TREKSTAR_DVDVIEW_H
#define TREKSTAR_DVDVIEW_H

#include "MaterialView.h"
#include "../../model/material/DVD.h"
#include "../../model/material/DVDInterface.h"

namespace TrekStar
{
    namespace Material
    {
        class DVDView : public MaterialView
        {
        private:
            DVD* GetModel() override;

        public:
            explicit DVDView(DVD & model);

            std::string GetNewContent();
            unsigned int GetUpdateOption() override;
            unsigned int GetAdditionalLanguageTrackNo();

            void PresentAdditionalLanguageTracks();
            void PresentAdditionalSubtitleTracks();
            void PresentBonusFeatures();

            std::string GetNewAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo);
        };
    }
}

#endif //TREKSTAR_DVDVIEW_H
