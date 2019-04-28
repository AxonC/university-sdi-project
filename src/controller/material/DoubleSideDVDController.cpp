#include "DoubleSideDVDController.h"

namespace TrekStar
{
    namespace Material
    {
        /**
            Class:                 DoubleSideDVDController
            Method Name:           DoubleSideDVDController (constructor)
            Method Access Control: Public

            Constructs the DoubleSideDVD controller based on the base class constructor.

            @param DoubleSideDVD object
            @param DoubleSideDVDView object
        */
        DoubleSideDVDController::DoubleSideDVDController(DoubleSideDVD & model, DoubleSideDVDView & view) : MaterialController(model, view) {}


        /**
            Class:                 DoubleSideDVDController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the DoubleSideDVD are to be updated.
        */
        void DoubleSideDVDController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
                                                                             // they wish to update.

            // Call the relevant private member function of DoubleSideDVDController based on user selection.
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
                this->UpdateSideOneContent();
                break;
            case 8:
                this->UpdateSideOneAdditionalLanguageTracks();
                break;
            case 9:
                this->UpdateSideOneAdditionalSubtitleTracks();
                break;
            case 10:
                this->UpdateSideOneBonusFeatures();
                break;
            case 11:
                this->UpdateSideTwoContent();
                break;
            case 12:
                this->UpdateSideTwoAdditionalLanguageTracks();
                break;
            case 13:
                this->UpdateSideTwoAdditionalSubtitleTracks();
                break;
            case 14:
                this->UpdateSideTwoBonusFeatures();
                break;
            default:
                break;
            }
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new DoubleSideDVD.
        */
        void DoubleSideDVDController::AddNew()
        {
            MaterialController::AddNew();  // Call the base class implementation to obtain base class information.
            this->UpdateSideOneContent();
            this->AddSideOneAdditionalLanguageTracks();
            this->AddSideOneAdditionalSubtitleTracks();
            this->AddSideOneBonusFeatures();
            this->UpdateSideTwoContent();
            this->AddSideTwoAdditionalSubtitleTracks();
            this->AddSideTwoAdditionalLanguageTracks();
            this->AddSideTwoBonusFeatures();
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideOneContent
           Method Access Control: Private

           Responsible for allowing the content for side one of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideOneContent()
        {
            this->GetModel()->SetSideOneContent(this->GetView()->GetNewSideOneContent());
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideOneAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing the additional language tracks on side one of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideOneAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideOneAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetSideOneAdditionalLanguageTrackNo();
            this->GetModel()->SetSideOneAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideOneAdditionalLanguageTrack(additionalLanguageTrackNo));
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideOneAdditionalSubtitleTracks
           Method Access Control: Private

           Responsible for allowing the additional subtitle tracks on side one of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideOneAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideOneAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideOneAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideOneBonusFeatures
           Method Access Control: Private

           Responsible for allowing the bonus features on side one of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideOneBonusFeatures()
        {
            this->GetView()->PresentSideOneBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideOneBonusFeatureNo();
            this->GetModel()->SetSideOneAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideOneBonusFeature(additionalSubtitleTrackNo));
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideTwoContent
           Method Access Control: Private

           Responsible for allowing the content for side two of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideTwoContent()
        {
            this->GetModel()->SetSideTwoContent(this->GetView()->GetNewSideTwoContent());
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           UpdateSideTwoAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing the additional language tracks on side two of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideTwoAdditionalLanguageTracks()
        {
            this->GetView()->PresentSideTwoAdditionalLanguageTracks();

            unsigned int additionalLanguageTrackNo = this->GetView()->GetSideTwoAdditionalLanguageTrackNo();
            this->GetModel()->SetSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo, this->GetView()->GetNewSideTwoAdditionalLanguageTrack(additionalLanguageTrackNo));
        }


        /**
          Class:                 DoubleSideDVDController
          Method Name:           UpdateSideTwoAdditionalSubtitleTracks
          Method Access Control: Private

          Responsible for allowing the additional subtitle tracks on side two of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideTwoAdditionalSubtitleTracks()
        {
            this->GetView()->PresentSideTwoAdditionalSubtitleTracks();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideTwoAdditionalSubtitleTrackNo();
            this->GetModel()->SetSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo));
        }


        /**
          Class:                 DoubleSideDVDController
          Method Name:           UpdateSideTwoBonusFeatures
          Method Access Control: Private

          Responsible for allowing the bonus features on side two of the DoubleSideDVD to be updated.
        */
        void DoubleSideDVDController::UpdateSideTwoBonusFeatures()
        {
            this->GetView()->PresentSideTwoBonusFeatures();

            unsigned int additionalSubtitleTrackNo = this->GetView()->GetSideTwoBonusFeatureNo();
            this->GetModel()->SetSideTwoAdditionalSubtitleTrack(additionalSubtitleTrackNo, this->GetView()->GetNewSideTwoBonusFeature(additionalSubtitleTrackNo));
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideOneAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing new additional language tracks to be added to side one of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideOneAdditionalLanguageTracks()
        {
            // Call method on view to get user input for how many additional language tracks should be added.
            unsigned int noOfAdditionalLanguageTracks = this->GetView()->GetNoOfSideOneAdditionalLanguageTracks();

            std::vector<std::string> sideOneAdditionalLanguageTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalLanguageTracks; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // language track.
                sideOneAdditionalLanguageTracks.push_back(this->GetView()->GetNewSideOneAdditionalLanguageTrack(i));
            }

            this->GetModel()->SetSideOneAdditionalLanguageTracks(sideOneAdditionalLanguageTracks);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideOneAdditionalSubtitleTracks
           Method Access Control: Private

           Responsible for allowing new additional subtitle tracks to be added to side one of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideOneAdditionalSubtitleTracks()
        {
            // Call method on view to get user input for how many additional subtitle tracks should be added.
            unsigned int noOfAdditionalSubtitleTracks = this->GetView()->GetNoOfSideOneAdditionalSubtitleTracks();

            std::vector<std::string> sideOneAdditionalSubtitleTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalSubtitleTracks; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // subtitle track.
                sideOneAdditionalSubtitleTracks.push_back(this->GetView()->GetNewSideOneAdditionalSubtitleTrack(i));
            }

            this->GetModel()->SetSideOneAdditionalSubtitleTracks(sideOneAdditionalSubtitleTracks);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideOneBonusFeatures
           Method Access Control: Private

           Responsible for allowing new bonus features to be added to side one of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideOneBonusFeatures()
        {
            // Call method on view to get user input for how many bonus features should be added.
            unsigned int noOfBonusFeatures = this->GetView()->GetNoOfSideOneBonusFeatures();

            std::vector<std::string> sideOneBonusFeatures;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfBonusFeatures; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new bonus
                // feature.
                sideOneBonusFeatures.push_back(this->GetView()->GetNewSideOneBonusFeature(i));
            }

            this->GetModel()->SetSideOneBonusFeatures(sideOneBonusFeatures);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideTwoAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing new additional language tracks to be added to side two of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideTwoAdditionalLanguageTracks()
        {
            // Call method on view to get user input for how many additional language tracks should be added.
            unsigned int noOfAdditionalLanguageTracks = this->GetView()->GetNoOfSideTwoAdditionalLanguageTracks();

            std::vector<std::string> sideTwoAdditionalLanguageTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalLanguageTracks; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // language track.
                sideTwoAdditionalLanguageTracks.push_back(this->GetView()->GetNewSideTwoAdditionalLanguageTrack(i));
            }

            this->GetModel()->SetSideTwoAdditionalLanguageTracks(sideTwoAdditionalLanguageTracks);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideTwoAdditionalSubtitleTracks
           Method Access Control: Private

           Responsible for allowing new additional subtitle tracks to be added to side two of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideTwoAdditionalSubtitleTracks()
        {
            // Call method on view to get user input for how many additional subtitle tracks should be added.
            unsigned int noOfAdditionalSubtitleTracks = this->GetView()->GetNoOfSideTwoAdditionalSubtitleTracks();

            std::vector<std::string> sideTwoAdditionalSubtitleTracks;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfAdditionalSubtitleTracks; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new additional
                // subtitle track.
                sideTwoAdditionalSubtitleTracks.push_back(this->GetView()->GetNewSideTwoAdditionalSubtitleTrack(i));
            }

            this->GetModel()->SetSideTwoAdditionalSubtitleTracks(sideTwoAdditionalSubtitleTracks);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           AddSideTwoBonusFeatures
           Method Access Control: Private

           Responsible for allowing new bonus features to be added to side two of the DoubleSideDVD.
        */
        void DoubleSideDVDController::AddSideTwoBonusFeatures()
        {
            // Call method on view to get user input for how many bonus features should be added.
            unsigned int noOfBonusFeatures = this->GetView()->GetNoOfSideTwoBonusFeatures();

            std::vector<std::string> sideTwoBonusFeatures;  // Create empty vector.

            for ( unsigned int i = 0; i < noOfBonusFeatures; i++ )
            {
                // Add to the vector the returned value from the view's method to get user input for a new bonus
                // feature.
                sideTwoBonusFeatures.push_back(this->GetView()->GetNewSideTwoBonusFeature(i));
            }

            this->GetModel()->SetSideTwoBonusFeatures(sideTwoBonusFeatures);
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the DoubleSideDVDs view object.

           @return A pointer to the DoubleSideDVDView object.
        */
        DoubleSideDVDView* DoubleSideDVDController::GetView()
        {
            return dynamic_cast<DoubleSideDVDView*>(MaterialController::GetView());
        }


        /**
           Class:                 DoubleSideDVDController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the DoubleSideDVDs model object.

           @return A pointer to the DoubleSideDVD object.
        */
        DoubleSideDVD* DoubleSideDVDController::GetModel()
        {
            return dynamic_cast<DoubleSideDVD*>(MaterialController::GetModel());
        }
    }
}