#include "DVDController.h"

namespace TrekStar
{
    namespace Material
    {
        /**
            Class:                 DVDController
            Method Name:           DVDController (constructor)
            Method Access Control: Public

            Constructs the DVD controller based on the base class constructor.

            @param DVD object
            @param DVDView object
        */
        DVDController::DVDController(DVD & model, DVDView & view) : MaterialController(model, view) {}


        /**
            Class:                 DVDController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the DVD are to be updated.
        */
        void DVDController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
            // they wish to update.

            // Call the relevant private member function of DVDController based on user selection.
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
                this->UpdateContent();
                break;
            case 8:
                this->UpdateAdditionalLanguageTracks();
                break;
            case 9:
                this->UpdateAdditionalSubtitleTracks();
                break;
            case 10:
                this->UpdateBonusFeatures();
                break;
            default:
                break;
            }
        }


        /**
           Class:                 DVDController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new DVD.
        */
        void DVDController::AddNew()
        {
            MaterialController::AddNew();  // Call the base class implementation to obtain base class information.
            this->UpdateContent();
            this->AddAdditionalLanguageTracks();
            this->AddAdditionalSubtitleTracks();
            this->AddBonusFeatures();
        }


        /**
           Class:                 DVDController
           Method Name:           UpdateContent
           Method Access Control: Private

           Responsible for allowing the content for the DVD to be updated.
        */
        void DVDController::UpdateContent()
        {
            this->GetModel()->SetContent(this->GetView()->GetNewContent());
        }


        /**
           Class:                 DVDController
           Method Name:           UpdateAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing the additional language tracks on the DVD to be updated.
        */
        void DVDController::UpdateAdditionalLanguageTracks()
        {
            this->GetView()->PresentAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetAdditionalLanguageTrackNo();
            this->GetModel()->SetAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewAdditionalLanguageTrack(additionalLanguageTrackNo));
        }


        /**
           Class:                 DVDController
           Method Name:           UpdateAdditionalSubtitleTracks
           Method Access Control: Private

           Responsible for allowing the additional subtitle tracks on the DVD to be updated.
        */
        void DVDController::UpdateAdditionalSubtitleTracks()
        {
            this->GetView()->PresentAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetAdditionalSubtitleTrackNo();
            this->GetModel()->SetAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }


        /**
           Class:                 DVDController
           Method Name:           UpdateBonusFeatures
           Method Access Control: Private

           Responsible for allowing the bonus features on the DVD to be updated.
        */
        void DVDController::UpdateBonusFeatures()
        {
            this->GetView()->PresentBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetBonusFeatureNo();
            this->GetModel()->SetAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewBonusFeature(additionalSubtitleTrackNo));
        }


        /**
           Class:                 DVDController
           Method Name:           AddAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing new additional language tracks to be added to the DVD.
        */
        void DVDController::AddAdditionalLanguageTracks()
        {
            // Call method on view to get user input for how many additional language tracks should be added.
            unsigned int noOfAdditionalLanguageTracks = this->GetView()->GetNoOfAdditionalLanguageTracks();

            std::vector<std::string> sideOneAdditionalLanguageTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalLanguageTracks; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // language track.
                sideOneAdditionalLanguageTracks.push_back(this->GetView()->GetNewAdditionalLanguageTrack(i));
            }

            this->GetModel()->SetAdditionalLanguageTracks(sideOneAdditionalLanguageTracks);
        }


        /**
           Class:                 DVDController
           Method Name:           AddAdditionalSubtitleTracks
           Method Access Control: Private

           Responsible for allowing new additional subtitle tracks to be added to the DVD.
        */
        void DVDController::AddAdditionalSubtitleTracks()
        {
            // Call method on view to get user input for how many additional subtitle tracks should be added.
            unsigned int noOfAdditionalSubtitleTracks = this->GetView()->GetNoOfAdditionalSubtitleTracks();

            std::vector<std::string> sideOneAdditionalSubtitleTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalSubtitleTracks; i++ )
            {
                sideOneAdditionalSubtitleTracks.push_back(this->GetView()->GetNewAdditionalSubtitleTrack(i));
            }

            this->GetModel()->SetAdditionalSubtitleTracks(sideOneAdditionalSubtitleTracks);
        }


        /**
           Class:                 DVDController
           Method Name:           AddBonus Features
           Method Access Control: Private

           Responsible for allowing new bonus features to be added to the DVD.
        */
        void DVDController::AddBonusFeatures()
        {
            unsigned int noOfBonusFeatures = this->GetView()->GetNoOfBonusFeatures();

            std::vector<std::string> sideOneBonusFeatures;

            for ( unsigned int i = 0; i < noOfBonusFeatures; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // subtitle track.
                sideOneBonusFeatures.push_back(this->GetView()->GetNewBonusFeature(i));
            }

            this->GetModel()->SetBonusFeatures(sideOneBonusFeatures);
        }


        /**
           Class:                 DVDController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the DVDs view object.

           @return A pointer to the DVDView object.
        */
        DVDView* DVDController::GetView()
        {
            return dynamic_cast<DVDView*>(MaterialController::GetView());
        }


        /**
           Class:                 DVDController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the DVDs model object.

           @return A pointer to the DVD object.
        */
        DVD* DVDController::GetModel()
        {
            return dynamic_cast<DVD*>(MaterialController::GetModel());
        }
    }
}