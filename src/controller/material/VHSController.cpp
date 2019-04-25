#include "VHSController.h"

namespace TrekStar
{
    namespace Material
    {
        VHSController::VHSController(VHS & model, VHSView & view) : MaterialController(model, view) {}

        void VHSController::UpdateAudioTrack()
        {
            this->GetModel()->SetAudioTrack(this->GetView()->GetNewAudioTrack());
        }

        void VHSController::UpdatePackaging()
        {
            
        }

        void VHSController::Update()
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
                this->UpdateAudioTrack();
                break;
            default:
                break;
            }
        }

        void VHSController::AddNew()
        {
            MaterialController::AddNew();
            this->UpdateAudioTrack();
        }

        VHSView* VHSController::GetView()
        {
            return dynamic_cast<VHSView*>(MaterialController::GetView());
        }

        VHS* VHSController::GetModel()
        {
            return dynamic_cast<VHS*>(MaterialController::GetModel());
        }
    }
}
