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

            unsigned int GetSideOneAdditionalLanguageTrackNo();
            unsigned int GetSideOneAdditionalSubtitleTrackNo();
            unsigned int GetSideOneBonusFeatureNo();
            unsigned int GetSideTwoAdditionalLanguageTrackNo();
            unsigned int GetSideTwoAdditionalSubtitleTrackNo();
            unsigned int GetSideTwoBonusFeatureNo();

            unsigned int GetNoOfSideOneAdditionalLanguageTracks();
            unsigned int GetNoOfSideOneAdditionalSubtitleTracks();
            unsigned int GetNoOfSideOneBonusFeatures();
            unsigned int GetNoOfSideTwoAdditionalLanguageTracks();
            unsigned int GetNoOfSideTwoAdditionalSubtitleTracks();
            unsigned int GetNoOfSideTwoBonusFeatures();

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
