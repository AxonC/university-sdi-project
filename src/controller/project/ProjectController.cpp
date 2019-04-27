#include "ProjectController.h"

#include "../../view/material/MaterialView.h"
#include "../material/MaterialController.h"
#include "../material/DVDController.h"
#include "../material/DoubleSideDVDController.h"
#include "../material/BoxSetController.h"
#include "../material/VHSController.h"
#include "../../view/people/CrewView.h"
#include "../people/CrewController.h"
#include "../../view/project/BoxOfficeReportView.h"
#include "../project/BoxOfficeReportController.h"
#include "../../model/material/MaterialFactory.h"

using TrekStar::Material::MaterialView;
using TrekStar::Material::MaterialController;
using TrekStar::Material::DVDView;
using TrekStar::Material::DVDController;
using TrekStar::Material::DoubleSideDVDView;
using TrekStar::Material::DoubleSideDVDController;
using TrekStar::Material::VHSView;
using TrekStar::Material::VHSController;
using TrekStar::Material::BoxSetView;
using TrekStar::Material::BoxSetController;
using TrekStar::People::CrewView;
using TrekStar::People::CrewController;
using TrekStar::Project::BoxOfficeReportView;
using TrekStar::Project::BoxOfficeReportController;

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
            case 6:
                this->UpdateCrew();
                break;
            default:
                break;
            }
        }

        void ProjectController::AddNew()
        {
            this->UpdateTitle();
            this->UpdateSummary();
            this->UpdateReleased();
            this->UpdatePlayingInTheatres();

            auto newProject = this->GetModel();
            _logger->info("Project " + std::to_string(newProject->GetId()) + " was added with the title of " + newProject->GetTitle());
        }

        void ProjectController::ListMaterials()
        {
            if ( this->GetModel()->GetMaterials().empty() )
            {
                this->GetView()->DisplayHasNoMaterials();
                return;
            }

            this->GetModel()->GetMaterials();

            unsigned int currentMaterial = 0;
            unsigned int commandInput = 0;

            while ( commandInput != 3 )
            {
                commandInput = this->GetView()->GetListMaterialsOption();

                if ( commandInput != 3 )
                {
                    currentMaterial = this->GetView()->GetCurrentMaterial(currentMaterial, commandInput);

                    const auto material = this->GetModel()->GetMaterials().at(currentMaterial);

                    MaterialView view(*material);
                    MaterialController controller(*material, view);
                    controller.ShowAll();
                }
            }
        }

        void ProjectController::AddMaterial()
        {
            std::shared_ptr<Material::Material> material = nullptr;

            while ( material == nullptr )
            {
                std::string format = this->GetView()->GetNewMaterialFormat();
                material = Material::MaterialFactory::Create(format);
            }

            try
            {
                this->GetModel()->AddMaterial(material);
            }
            catch (std::domain_error &)
            {
                this->GetView()->DisplayCannotAddMaterial();
                return;
            }

            if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::VHS>(material) )
            {
                VHSView view(*castedMaterial);
                VHSController controller(*castedMaterial, view);

                controller.SetFormat("vhs");
                controller.AddNew();

                this->LogMaterialAdd(castedMaterial);
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(material) )
            {
                BoxSetView view(*castedMaterial);
                BoxSetController controller(*castedMaterial, view);

                controller.SetFormat("boxset");
                controller.AddNew();

                this->LogMaterialAdd(castedMaterial);
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material) )
            {
                DoubleSideDVDView view(*castedMaterial);
                DoubleSideDVDController controller(*castedMaterial, view);

                controller.SetFormat("dsdvd");
                controller.AddNew();

                this->LogMaterialAdd(castedMaterial);
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material) )
            {
                DVDView view(*castedMaterial);
                DVDController controller(*castedMaterial, view);

                controller.SetFormat("dvd");
                controller.AddNew();

                this->LogMaterialAdd(castedMaterial);
            }
        }

        void ProjectController::UpdateMaterials()
        {
            if ( this->GetModel()->GetMaterials().empty() )
            {
                this->GetView()->DisplayHasNoMaterials();
                return;
            }

            this->GetView()->PresentMaterialsList();

            auto material = this->GetModel()->GetMaterials().at(this->GetView()->GetMaterialSelection());

            if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(material) )
            {
                BoxSetView view(*castedMaterial);
                BoxSetController controller(*castedMaterial, view);

                controller.Update();
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::VHS>(material) )
            {
                VHSView view(*castedMaterial);
                VHSController controller(*castedMaterial, view);

                controller.Update();
            }
            else if ( auto castedMaterial = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(material) )
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
            if ( this->GetModel()->GetMaterials().empty() )
            {
                this->GetView()->DisplayHasNoMaterials();
                return;
            }

            this->GetView()->PresentMaterialsList();

            auto material = this->GetModel()->GetMaterials().at(this->GetView()->GetMaterialSelection());
            this->GetModel()->RemoveMaterial(material);
        }

        void ProjectController::ListCrew()
        {
            if ( this->GetModel()->GetCrew().empty() )
            {
                this->GetView()->DisplayHasNoCrew();
                return;
            }

            this->GetModel()->GetCrew();

            unsigned int currentCrew = 0;
            unsigned int commandInput = 0;

            while ( commandInput != 3 )
            {
                commandInput = this->GetView()->GetListCrewOption();

                if ( commandInput != 3 )
                {
                    currentCrew = this->GetView()->GetCurrentCrew(currentCrew, commandInput);

                    const auto crew = this->GetModel()->GetCrew().at(currentCrew);

                    CrewView view(*crew);
                    CrewController controller(*crew, view);
                    controller.ShowAll();
                }
            }
        }

        void ProjectController::AddCrew()
        {
            People::Crew crew;

            CrewView view(crew);
            CrewController controller(crew, view);

            controller.AddNew();

            this->GetModel()->AddCrew(std::make_shared<People::Crew>(crew));
        }

        void ProjectController::UpdateCrew()
        {
            if ( this->GetModel()->GetCrew().empty() )
            {
                this->GetView()->DisplayHasNoCrew();
                return;
            }

            this->GetView()->PresentCrewList();

            auto crew = this->GetModel()->GetCrew().at(this->GetView()->GetCrewSelection());

            CrewView view(*crew);
            CrewController controller(*crew, view);

            controller.Update();
        }

        void ProjectController::RemoveCrew()
        {
            if ( this->GetModel()->GetCrew().empty() )
            {
                this->GetView()->DisplayHasNoCrew();
                return;
            }

            this->GetView()->PresentCrewList();

            auto crew = this->GetModel()->GetCrew().at(this->GetView()->GetCrewSelection());
            this->GetModel()->RemoveCrew(crew);
        }

        void ProjectController::ListBoxOfficeReports()
        {
            if ( this->GetModel()->GetBoxOfficeReports().empty() )
            {
                this->GetView()->DisplayHasNoBoxOfficeReports();
                return;
            }

            this->GetModel()->GetBoxOfficeReports();

            unsigned int currentBoxOfficeReport = 0;
            unsigned int commandInput = 0;

            while ( commandInput != 3 )
            {
                commandInput = this->GetView()->GetListBoxOfficeReportsOption();

                if ( commandInput != 3 )
                {
                    currentBoxOfficeReport = this->GetView()->GetCurrentBoxOfficeReport(currentBoxOfficeReport, commandInput);

                    const auto boxOfficeReport = this->GetModel()->GetBoxOfficeReports().at(currentBoxOfficeReport);

                    BoxOfficeReportView view(*boxOfficeReport);
                    BoxOfficeReportController controller(*boxOfficeReport, view);
                    controller.ShowAll();
                }
            }
        }

        void ProjectController::AddBoxOfficeReport()
        {
            TrekStar::Project::BoxOfficeReport boxOfficeReport;

            BoxOfficeReportView view(boxOfficeReport);
            BoxOfficeReportController controller(boxOfficeReport, view);

            controller.AddNew();

            this->GetModel()->AddBoxOfficeReport(std::make_shared<TrekStar::Project::BoxOfficeReport>(boxOfficeReport));
        }

        void ProjectController::RemoveBoxOfficeReport()
        {
            if ( this->GetModel()->GetBoxOfficeReports().empty() )
            {
                this->GetView()->DisplayHasNoBoxOfficeReports();
                return;
            }

            this->GetView()->PresentBoxOfficeReportsList();

            auto crew = this->GetModel()->GetCrew().at(this->GetView()->GetCrewSelection());
            this->GetModel()->RemoveCrew(crew);
        }

        bool ProjectController::ActorExists(std::string & searchCriteria)
        {
            std::transform(searchCriteria.begin(), searchCriteria.end(), searchCriteria.begin(), ::tolower);

            for ( const auto & crew: this->GetModel()->GetCrew() )
            {
                std::string name = crew->GetName();
                std::transform(name.begin(), name.end(), name.begin(), ::tolower);

                std::string jobTitle = crew->GetJobTitle();
                std::transform(jobTitle.begin(), jobTitle.end(), jobTitle.begin(), ::tolower);

                if ( jobTitle == "actor" && name == searchCriteria )
                {
                    return true;
                }
            }

            return false;
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

        void ProjectController::LogMaterialAdd(const std::shared_ptr<Material::Material>& material)
        {
            _logger->info("Material " + std::to_string(material->GetId()) + " was added to project " + std::to_string(this->GetModel()->GetId()));
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
