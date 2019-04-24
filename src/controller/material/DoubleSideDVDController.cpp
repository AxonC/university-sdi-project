#include "DoubleSideDVDController.h"

namespace TrekStar
{
    namespace Material
    {
        DoubleSideDVDController::DoubleSideDVDController(DoubleSideDVD & model, DoubleSideDVDView & view) : MaterialController(model, view) {}

        void DoubleSideDVDController::UpdateSideOneContent()
        {
            this->GetModel()->SetSideOneContent(this->GetView()->GetNewSideOneContent());
        }

        void DoubleSideDVDController::UpdateSideOneAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideOneAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetAdditionalLanguageTrackNo();
            this->GetModel()->SetSideOneAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideOneAdditionalLanguageTrack(additionalLanguageTrackNo));
        }

        void DoubleSideDVDController::UpdateSideOneAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideOneAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideOneBonusFeatures()
        {
            this->GetView()->PresentSideOneBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetBonusFeatureNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneBonusFeature(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoContent()
        {
            this->GetModel()->SetSideTwoContent(this->GetView()->GetNewSideTwoContent());
        }

        void DoubleSideDVDController::UpdateSideTwoAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideTwoAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetAdditionalLanguageTrackNo();
            this->GetModel()->SetSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideTwoAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoBonusFeatures()
        {
            this->GetView()->PresentSideTwoBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetBonusFeatureNo();
            this->GetModel()->SetSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideTwoBonusFeature(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();

            switch ( commandInput )
            {
            case 1:
                this->UpdateAudioFormat();
                break;
            case 2:
                this->UpdateRunTime();
                break;
            case 3:
                this->UpdateLanguage();
                break;
            case 4:
                this->UpdateRetailPrice();
                break;
            case 5:
                this->UpdateSubtitles();
                break;
            case 6:
                this->UpdateFrameAspect();
                break;
            case 7:
                this->UpdatePackaging();
                break;
            case 8:
                this->UpdateSideOneContent();
                break;
            case 9:
                this->UpdateSideOneAdditionalLanguageTracks();
                break;
            case 10:
                this->UpdateSideOneAdditionalSubtitleTracks();
                break;
            case 11:
                this->UpdateSideOneBonusFeatures();
                break;
            case 12:
                this->UpdateSideTwoContent();
                break;
            case 13:
                this->UpdateSideTwoAdditionalLanguageTracks();
                break;
            case 14:
                this->UpdateSideTwoAdditionalSubtitleTracks();
                break;
            case 15:
                this->UpdateSideTwoBonusFeatures();
                break;
            default:
                break;
            }
        }

        DoubleSideDVDView* DoubleSideDVDController::GetView()
        {
            return dynamic_cast<DoubleSideDVDView*>(MaterialController::GetView());
        }

        DoubleSideDVD* DoubleSideDVDController::GetModel()
        {
            return dynamic_cast<DoubleSideDVD*>(MaterialController::GetModel());
        }
    }
}