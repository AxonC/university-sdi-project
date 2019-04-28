#include "VHSController.h"

namespace TrekStar
{
    namespace Material
    {
        /**
            Class:                 VHSController
            Method Name:           VHSController (constructor)
            Method Access Control: Public

            Constructs the VHS controller based on the base class constructor.

            @param VHS object
            @param VHSView object
        */
        VHSController::VHSController(VHS & model, VHSView & view) : MaterialController(model, view) {}


        /**
            Class:                 VHSController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the VHS are to be updated.
        */
        void VHSController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
                                                                             // they wish to update.

            // Call the relevant private member function of VHSController based on user selection.
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


        /**
           Class:                 VHSController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new VHS.
        */
        void VHSController::AddNew()
        {
            MaterialController::AddNew();
            this->UpdateAudioTrack();
            this->UpdatePackaging();
        }


        /**
           Class:                 VHSController
           Method Name:           UpdateAudioTrack
           Method Access Control: Private

           Responsible for allowing the audio track on the VHS to be updated.
        */
        void VHSController::UpdateAudioTrack()
        {
            this->GetModel()->SetAudioTrack(this->GetView()->GetNewAudioTrack());
        }


        /**
           Class:                 VHSController
           Method Name:           UpdatePackaging
           Method Access Control: Private

           Responsible for allowing the packaging of the VHS to be updated.
        */
        void VHSController::UpdatePackaging()
        {
            this->GetView()->PresentPermittedPackaging();
            this->GetModel()->SetPackaging(this->GetModel()->GetPermittedPackaging().at(this->GetView()->GetNewPackaging()));
        }


        /**
           Class:                 VHSController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the VHSs view object.

           @return A pointer to the VHSView object.
        */
        VHSView* VHSController::GetView()
        {
            return dynamic_cast<VHSView*>(MaterialController::GetView());
        }


        /**
           Class:                 VHSController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the VHSs model object.

           @return A pointer to the VHS object.
        */
        VHS* VHSController::GetModel()
        {
            return dynamic_cast<VHS*>(MaterialController::GetModel());
        }
    }
}
