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

        void DoubleSideDVDController::AddSideOneAdditionalLanguageTracks()
        {
            unsigned int noOfAdditionalLanguageTracks = this->GetView()->GetNoOfSideOneAdditionalLanguageTracks();

            std::vector<std::string> sideOneAdditionalLanguageTracks;

            for ( unsigned int i = 0; i < noOfAdditionalLanguageTracks; i++ )
            {
                sideOneAdditionalLanguageTracks.push_back(this->GetView()->GetNewSideOneAdditionalLanguageTrack(i));
            }

            this->GetModel()->SetSideOneAdditionalLanguageTracks(sideOneAdditionalLanguageTracks);
        }

        void DoubleSideDVDController::AddSideOneAdditionalSubtitleTracks()
        {
            unsigned int noOfAdditionalSubtitleTracks = this->GetView()->GetNoOfSideOneAdditionalSubtitleTracks();

            std::vector<std::string> sideOneAdditionalSubtitleTracks;

            for ( unsigned int i = 0; i < noOfAdditionalSubtitleTracks; i++ )
            {
                sideOneAdditionalSubtitleTracks.push_back(this->GetView()->GetNewSideOneAdditionalSubtitleTrack(i));
            }

            this->GetModel()->SetSideOneAdditionalSubtitleTracks(sideOneAdditionalSubtitleTracks);
        }

        void DoubleSideDVDController::AddSideOneBonusFeatures()
        {
            unsigned int noOfBonusFeatures = this->GetView()->GetNoOfSideOneBonusFeatures();

            std::vector<std::string> sideOneBonusFeatures;

            for ( unsigned int i = 0; i < noOfBonusFeatures; i++ )
            {
                sideOneBonusFeatures.push_back(this->GetView()->GetNewSideOneBonusFeature(i));
            }

            this->GetModel()->SetSideOneBonusFeatures(sideOneBonusFeatures);
        }

        void DoubleSideDVDController::AddSideTwoAdditionalLanguageTracks()
        {
            unsigned int noOfAdditionalLanguageTracks = this->GetView()->GetNoOfSideTwoAdditionalLanguageTracks();

            std::vector<std::string> sideTwoAdditionalLanguageTracks;

            for ( unsigned int i = 0; i < noOfAdditionalLanguageTracks; i++ )
            {
                sideTwoAdditionalLanguageTracks.push_back(this->GetView()->GetNewSideTwoAdditionalLanguageTrack(i));
            }

            this->GetModel()->SetSideTwoAdditionalLanguageTracks(sideTwoAdditionalLanguageTracks);
        }

        void DoubleSideDVDController::AddSideTwoAdditionalSubtitleTracks()
        {
            unsigned int noOfAdditionalSubtitleTracks = this->GetView()->GetNoOfSideTwoAdditionalSubtitleTracks();

            std::vector<std::string> sideTwoAdditionalSubtitleTracks;

            for ( unsigned int i = 0; i < noOfAdditionalSubtitleTracks; i++ )
            {
                sideTwoAdditionalSubtitleTracks.push_back(this->GetView()->GetNewSideTwoAdditionalSubtitleTrack(i));
            }

            this->GetModel()->SetSideTwoAdditionalSubtitleTracks(sideTwoAdditionalSubtitleTracks);
        }

        void DoubleSideDVDController::AddSideTwoBonusFeatures()
        {
            unsigned int noOfBonusFeatures = this->GetView()->GetNoOfSideTwoBonusFeatures();

            std::vector<std::string> sideTwoBonusFeatures;

            for ( unsigned int i = 0; i < noOfBonusFeatures; i++ )
            {
                sideTwoBonusFeatures.push_back(this->GetView()->GetNewSideTwoBonusFeature(i));
            }

            this->GetModel()->SetSideTwoBonusFeatures(sideTwoBonusFeatures);
        }

        void DoubleSideDVDController::UpdateSideOneAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideOneAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetSideOneAdditionalLanguageTrackNo();
            this->GetModel()->SetSideOneAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideOneAdditionalLanguageTrack(additionalLanguageTrackNo));
        }

        void DoubleSideDVDController::UpdateSideOneAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideOneAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideOneAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideOneBonusFeatures()
        {
            this->GetView()->PresentSideOneBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideOneBonusFeatureNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneBonusFeature(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoContent()
        {
            this->GetModel()->SetSideTwoContent(this->GetView()->GetNewSideTwoContent());
        }

        void DoubleSideDVDController::UpdateSideTwoAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideTwoAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetSideTwoAdditionalLanguageTrackNo();
            this->GetModel()->SetSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideTwoAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideTwoAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }

        void DoubleSideDVDController::UpdateSideTwoBonusFeatures()
        {
            this->GetView()->PresentSideTwoBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideTwoBonusFeatureNo();
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

        void DoubleSideDVDController::AddNew()
        {
            MaterialController::AddNew();
            this->UpdateSideOneContent();
            this->AddSideOneAdditionalLanguageTracks();
            this->AddSideOneAdditionalSubtitleTracks();
            this->AddSideOneBonusFeatures();
            this->UpdateSideTwoContent();
            this->AddSideTwoAdditionalSubtitleTracks();
            this->AddSideTwoAdditionalLanguageTracks();
            this->AddSideTwoBonusFeatures();
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