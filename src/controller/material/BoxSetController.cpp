#include "BoxSetController.h"

#include "DVDController.h"
#include "DoubleSideDVDController.h"
#include "../../model/material/MaterialFactory.h"

namespace TrekStar
{
    namespace Material
    {
        /**
            Class:                 BoxSetController
            Method Name:           BoxSetController (constructor)
            Method Access Control: Public

            Takes a model and a view. Constructs the BoxSet controller based on the base class constructor.

            @param BoxSet object
            @param BoxSetView object
        */
        BoxSetController::BoxSetController(BoxSet & model, BoxSetView & view) : MaterialController(model, view) {}


        /**
            Class:                 BoxOfficeController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the BoxSet are to be updated.
        */
        void BoxSetController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
                                                                             // they wish to update.

            // Call the relevant private member function of BoxSetController based on user selection.
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
                this->AddDisk();
                break;
            case 8:
                this->UpdateDisks();
                break;
            case 9:
                this->RemoveDisk();
                break;
            default:
                break;
            }
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to add a new disk to the box set.
        */
        void BoxSetController::AddNew()
        {
            MaterialController::AddNew();
            this->AddDisks();
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           AddDisks
           Method Access Control: Private

           Responsible for allowing multiple disks to be added to the BoxSet when a new BoxSet is created.
        */
        void BoxSetController::AddDisks()
        {
            unsigned int noOfDisks = this->GetView()->GetNoOfDisks();

            for ( int i = 0; i < noOfDisks; i++)
            {
                this->AddDisk();
            }
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           AddDisk
           Method Access Control: Private

           Responsible for allowing a single disk to be added to the BoxSet when an existing BoxSet is being updated.
        */
        void BoxSetController::AddDisk()
        {
            this->GetModel()->AddDisk(this->GetNewDisk());
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           UpdateDisks
           Method Access Control: Private

           Responsible for allowing the user to update information pertaining to a selected disk in a BoxSet.
        */
        void BoxSetController::UpdateDisks()
        {
            this->GetView()->PresentDisks();  // Display a list of disks in the BoxSet to the user.

            unsigned int diskNo = this->GetView()->GetDiskNo();  // Get user selection for the disk they wish to update.

            this->GetModel()->SetDisk(this->GetNewDisk(), diskNo);  // Update the disk in the model with the new
                                                                    // information provided by the user.
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           RemoveDisk
           Method Access Control: Private

           Responsible for allowing the user to "pop" a disk off the stack of disks contained within a BoxSet.
        */
        void BoxSetController::RemoveDisk()
        {
            this->GetView()->PresentLastDisk();  // Display the disk to be removed.

            bool removeConfirmed = this->GetView()->GetRemoveConfirmation();  // Confirm the removal with the user.

            if ( removeConfirmed )  // If the user confirms the deletion of the disk.
            {
                this->GetModel()->RemoveDisk();  // Call the model's method to pop a disk from the stack.
            }
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           GetNewDisk
           Method Access Control: Private

           Responsible for obtaining information for a new disk to be added to a BoxSet.

           @return A shared pointer to the new disk object.
        */
        std::shared_ptr<DVD> BoxSetController::GetNewDisk()
        {
            unsigned int diskType = this->GetView()->GetNewDiskType();  // Get user selection on disk material format.

            std::shared_ptr<TrekStar::Material::Material> material = nullptr;  // Create a NULL Material object.

            if ( diskType == 1 || diskType == 3 )  // If the disk format is a DVD or Bluray.
            {
                material = MaterialFactory::Create("dvd");  // Obtain a DVD object from the Material factory.

                // Cast the pointer to an object.
                auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material);

                DVDView view(*castedMaterial);
                DVDController controller(*castedMaterial, view);

                if ( diskType == 1 )  // If the disk format is a DVD.
                {
                    controller.SetFormat("dvd");
                }
                else  // If the disk format is a Bluray.
                {
                    controller.SetFormat("bluray");
                }

                controller.AddNew();  // Call the AddNew method on the newly created disk object in order to populate it
                                      // with the relevant information.

                return castedMaterial;
            }
            else
            {
                material = MaterialFactory::Create("dsdvd");  // Obtain a DoubleSideDVD object from the Material factory.

                // Cast the pointer to an object.
                auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material);

                DoubleSideDVDView view(*castedMaterial);
                DoubleSideDVDController controller(*castedMaterial, view);

                controller.SetFormat("dsdvd");

                controller.AddNew();  // Call the AddNew method on the newly created disk object in order to populate it
                // with the relevant information.

                return castedMaterial;
            }
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the BoxSets view object.

           @return A pointer to the BoxSetView object.
        */
        BoxSetView* BoxSetController::GetView()
        {
            // Call the base class implementation of GetView and cast the returned MaterialView to BoxSetView.
            return dynamic_cast<BoxSetView*>(MaterialController::GetView());
        }


        /**
           Class:                 BoxOfficeController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the BoxSets model object.

           @return A pointer to the BoxSet object.
        */
        BoxSet* BoxSetController::GetModel()
        {
            // Call the base class implementation of GetModel and cast the returned MaterialInterface to BoxSet.
            return dynamic_cast<BoxSet*>(MaterialController::GetModel());
        }
    }
}
