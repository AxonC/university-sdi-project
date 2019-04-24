#include "DVDController.h"

#include <iostream>

namespace TrekStar
{
    namespace Material
    {
        DVDController::DVDController(DVD & model, DVDView & view) : MaterialController(model, view) {}

        void DVDController::UpdateContent()
        {
            this->GetModel()->SetContent(this->GetView()->GetNewContent());
        }

        void DVDController::UpdateAdditionalLanguageTracks()
        {
            this->GetView()->PresentAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetAdditionalLanguageTrackNo();
            this->GetModel()->SetAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewAdditionalLanguageTrack(additionalLanguageTrackNo));
        }

        void DVDController::UpdateAdditionalSubtitleTracks()
        {
            this->GetView()->PresentAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetAdditionalSubtitleTrackNo();
            this->GetModel()->SetAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }

        void DVDController::UpdateBonusFeatures()
        {
            this->GetView()->PresentBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetBonusFeatureNo();
            this->GetModel()->SetAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewBonusFeature(additionalSubtitleTrackNo));
        }

        void DVDController::Update()
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
                this->UpdateContent();
                break;
            case 9:
                this->UpdateAdditionalLanguageTracks();
                break;
            case 10:
                this->UpdateAdditionalSubtitleTracks();
                break;
            case 11:
                this->UpdateBonusFeatures();
                break;
            default:
                break;
            }
        }

        void DVDController::UpdateAll()
        {
            MaterialController::UpdateAll();
            this->UpdateContent();
            this->UpdateAdditionalLanguageTracks();
            this->UpdateAdditionalSubtitleTracks();
            this->UpdateBonusFeatures();
        }

        DVDView* DVDController::GetView()
        {
            return dynamic_cast<DVDView*>(MaterialController::GetView());
        }

        DVD* DVDController::GetModel()
        {
            return dynamic_cast<DVD*>(MaterialController::GetModel());
        }
    }
}