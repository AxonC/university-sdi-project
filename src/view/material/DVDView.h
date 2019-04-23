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
            unsigned int GetAdditionalSubtitleTrackNo();
            unsigned int GetBonusFeatureNo();

            void PresentAdditionalLanguageTracks();
            void PresentAdditionalSubtitleTracks();
            void PresentBonusFeatures();

            std::string GetNewAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo);
            std::string GetNewAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo);
            std::string GetNewBonusFeature(const unsigned int & bonusFeatureNo);
        };
    }
}

#endif //TREKSTAR_DVDVIEW_H
