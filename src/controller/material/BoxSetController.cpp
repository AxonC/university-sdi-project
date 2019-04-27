#include "BoxSetController.h"

#include "DVDController.h"
#include "DoubleSideDVDController.h"
#include "../../model/material/MaterialFactory.h"

namespace TrekStar
{
    namespace Material
    {
        BoxSetController::BoxSetController(BoxSet & model, BoxSetView & view) : MaterialController(model, view) {}

        void BoxSetController::Update()
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

        void BoxSetController::AddNew()
        {
            MaterialController::AddNew();
            this->AddDisks();
        }

        void BoxSetController::UpdateDisks()
        {
            this->GetView()->PresentDisks();

            unsigned int diskNo = this->GetView()->GetDiskNo();

            this->GetModel()->SetDisk(this->GetNewDisk(), diskNo);
        }

        void BoxSetController::AddDisks()
        {
            unsigned int noOfDisks = this->GetView()->GetNoOfDisks();

            for ( int i = 0; i < noOfDisks; i++)
            {
                this->AddDisk();
            }
        }

        void BoxSetController::AddDisk()
        {
            this->GetModel()->AddDisk(this->GetNewDisk());
        }

        void BoxSetController::RemoveDisk()
        {
            this->GetView()->PresentLastDisk();

            bool removeConfirmed = this->GetView()->GetRemoveConfirmation();

            if ( removeConfirmed )
            {
                this->GetModel()->RemoveDisk();
            }
        }

        std::shared_ptr<DVD> BoxSetController::GetNewDisk()
        {
            unsigned int diskType = this->GetView()->GetNewDiskType();

            std::shared_ptr<TrekStar::Material::Material> material = nullptr;

            if ( diskType == 1 )
            {
                material = MaterialFactory::Create("dvd");
                auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material);

                DVDView view(*castedMaterial);
                DVDController controller(*castedMaterial, view);

                controller.SetFormat("dvd");
                controller.AddNew();

                return castedMaterial;
            }
            else if ( diskType == 2 )
            {
                material = MaterialFactory::Create("dsdvd");
                auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material);

                DoubleSideDVDView view(*castedMaterial);
                DoubleSideDVDController controller(*castedMaterial, view);

                controller.SetFormat("dsdvd");
                controller.AddNew();

                return castedMaterial;
            }
            else
            {
                // TO DO: Bluray
            }
        }

        BoxSetView* BoxSetController::GetView()
        {
            return dynamic_cast<BoxSetView*>(MaterialController::GetView());
        }

        BoxSet* BoxSetController::GetModel()
        {
            return dynamic_cast<BoxSet*>(MaterialController::GetModel());
        }
    }
}
