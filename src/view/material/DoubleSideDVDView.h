#ifndef TREKSTAR_DOUBLESIDEDVDVIEW_H
#define TREKSTAR_DOUBLESIDEDVDVIEW_H

#include "MaterialView.h"
#include "../../model/material/DoubleSideDVD.h"
#include "../../model/material/DoubleSideDVDInterface.h"

namespace TrekStar
{
    namespace Material
    {
        class DoubleSideDVDView : public MaterialView
        {
        public:
            explicit DoubleSideDVDView(DoubleSideDVD & model);

            unsigned int GetUpdateOption() override;

            unsigned int GetAdditionalLanguageTrackNo();
            unsigned int GetAdditionalSubtitleTrackNo();
            unsigned int GetBonusFeatureNo();

            void PresentSideOneAdditionalLanguageTracks();
            void PresentSideOneAdditionalSubtitleTracks();
            void PresentSideOneBonusFeatures();
            void PresentSideTwoAdditionalLanguageTracks();
            void PresentSideTwoAdditionalSubtitleTracks();
            void PresentSideTwoBonusFeatures();

            std::string GetNewSideOneContent();
            std::string GetNewSideOneAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo);
            std::string GetNewSideOneAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo);
            std::string GetNewSideOneBonusFeature(const unsigned int & bonusFeatureNo);
            std::string GetNewSideTwoContent();
            std::string GetNewSideTwoAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo);
            std::string GetNewSideTwoAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo);
            std::string GetNewSideTwoBonusFeature(const unsigned int & bonusFeatureNo);

        private:
            DoubleSideDVD* GetModel() override;
        };
    }
}

#endif //TREKSTAR_DOUBLESIDEDVDVIEW_H
