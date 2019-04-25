#include "ProjectController.h"

#include "../../view/material/MaterialView.h"
#include "../material/MaterialController.h"
#include "../material/DVDController.h"
#include "../material/DoubleSideDVDController.h"
#include "../../model/material/MaterialFactory.h"

using TrekStar::Material::MaterialView;
using TrekStar::Material::MaterialController;
using TrekStar::Material::DVDView;
using TrekStar::Material::DVDController;
using TrekStar::Material::DoubleSideDVDView;
using TrekStar::Material::DoubleSideDVDController;

namespace TrekStar
{
    namespace Project
    {
        ProjectController::ProjectController(ProjectInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void ProjectController::ShowAll()
        {
            this->view->PresentAll();
        }

        void ProjectController::ShowList()
        {
            this->view->PresentList();
        }

        void ProjectController::UpdateProject()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();

            switch ( commandInput )
            {
            case 1:
                this->UpdateTitle();
                break;
            case 2:
                this->UpdateSummary();
                break;
            case 3:
                this->UpdateReleased();
                break;
            case 4:
                this->UpdatePlayingInTheatres();
                break;
            case 5:
                this->UpdateKeyword();
                break;
            default:
                break;
            }
        }

        void ProjectController::UpdateAll()
        {
            this->UpdateTitle();
            this->UpdateSummary();
            this->UpdateReleased();
            this->UpdatePlayingInTheatres();
        }

        void ProjectController::AddMaterial()
        {
            std::shared_ptr<Material::Material> material = nullptr;

//            while ( currentMaterial == nullptr )
//            {
                std::string format = this->GetView()->GetNewMaterialFormat();
                material = Material::MaterialFactory::Create(format);
            //}

            this->GetModel()->AddMaterial(material);

            if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material) )
            {
                DoubleSideDVDView view(*castedMaterial);
                DoubleSideDVDController controller(*castedMaterial, view);

                controller.SetFormat("dsdvd");
                controller.UpdateAll();
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material) )
            {
                DVDView view(*castedMaterial);
                DVDController controller(*castedMaterial, view);

                controller.SetFormat("dvd");
                controller.UpdateAll();
            }
        }

        void ProjectController::UpdateMaterials()
        {
            this->GetView()->PresentMaterialsList();

            auto material = this->GetModel()->GetMaterials().at(this->GetView()->GetMaterialSelection());

            if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material) )
            {
                DoubleSideDVDView view(*castedMaterial);
                DoubleSideDVDController controller(*castedMaterial, view);

                controller.Update();
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material) )
            {
                DVDView view(*castedMaterial);
                DVDController controller(*castedMaterial, view);

                controller.Update();
            }
            else
            {
                MaterialView view(*material);
                MaterialController controller(*material, view);

                controller.Update();
            }
        }

        void ProjectController::RemoveMaterial()
        {
            this->GetView()->PresentMaterialsList();

            auto material = this->GetModel()->GetMaterials().at(this->GetView()->GetMaterialSelection());

            this->GetModel()->RemoveMaterial(material);
        }

        void ProjectController::UpdateTitle()
        {
            this->GetModel()->SetTitle(this->GetView()->GetNewTitle());
        }

        void ProjectController::UpdateSummary()
        {
            this->GetModel()->SetSummary(this->GetView()->GetNewSummary());
        }

        void ProjectController::UpdateReleased()
        {
            this->GetModel()->SetReleased(this->GetView()->GetNewReleased());
        }

        void ProjectController::UpdatePlayingInTheatres()
        {
            this->GetModel()->SetPlayingInTheatres(this->GetView()->GetNewPlayingInTheatres());
        }

        void ProjectController::UpdateKeyword()
        {
            this->GetView()->PresentKeywords();

            unsigned int keywordNo = this->GetView()->GetKeywordNo();
            this->GetModel()->SetKeyword(keywordNo, this->GetView()->GetNewKeyword(keywordNo));
        }

        ProjectInterface* ProjectController::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }

        ProjectView* ProjectController::GetView()
        {
            return dynamic_cast<ProjectView*>(this->view);
        }
    }
}
