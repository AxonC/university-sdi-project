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
        /**
            Class:                 ProjectController
            Method Name:           ProjectController (constructor)
            Method Access Control: Public

            Constructs the Project controller based on the base class constructor.

            @param ProjectInterface object
            @param ViewInterface object
        */
        ProjectController::ProjectController(ProjectInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }


        /**
            Class:                 ProjectController
            Method Name:           ShowAll
            Method Access Control: Public

            Responsible for ordering the view to display all information for the Project.
        */
        void ProjectController::ShowAll()
        {
            this->view->PresentAll();
        }


        /**
            Class:                 ProjectController
            Method Name:           ShowList
            Method Access Control: Public

            Responsible for ordering the view to display a summary list of information for the Project.
        */
        void ProjectController::ShowList()
        {
            this->view->PresentList();
        }


        /**
            Class:                 ProjectController
            Method Name:           UpdateProject
            Method Access Control: Public

            Responsible for determining which attributes of the Project are to be updated.
        */
        void ProjectController::UpdateProject()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
                                                                             // they wish to update.

            // Call the relevant private member function of ProjectController based on user selection.
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


        /**
           Class:                 ProjectController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new Project.
        */
        void ProjectController::AddNew()
        {
            this->UpdateTitle();
            this->UpdateSummary();
            this->UpdateReleased();
            this->UpdatePlayingInTheatres();

            auto newProject = this->GetModel();
            _logger->info("Project " + std::to_string(newProject->GetId()) + " was added with the title of " + newProject->GetTitle());
        }


        /**
           Class:                 ProjectController
           Method Name:           ListMaterials
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for the Materials in the Project and allowing the user
           to view their details.
        */
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


        /**
           Class:                 ProjectController
           Method Name:           AddMaterial
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for a new Material to be added to the Project.
        */
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


        /**
            Class:                 ProjectController
            Method Name:           UpdateMaterials
            Method Access Control: Public

            Responsible for interfacing with the View/Controller for a Material whose attributes are to be updated.
        */
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


        /**
            Class:                 ProjectController
            Method Name:           RemoveMaterial
            Method Access Control: Public

            Responsible for interfacing with the View/Controller for a Material that is to be removed from the Project.
        */
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


        /**
           Class:                 ProjectController
           Method Name:           ListCrew
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for the Crew in the Project and allowing the user
           to view their details.
        */
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


        /**
           Class:                 ProjectController
           Method Name:           AddCrew
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for a new Crew to be added to the Project.
        */
        void ProjectController::AddCrew()
        {
            People::Crew crew;

            CrewView view(crew);
            CrewController controller(crew, view);

            controller.AddNew();

            this->GetModel()->AddCrew(std::make_shared<People::Crew>(crew));
        }


        /**
            Class:                 ProjectController
            Method Name:           UpdateCrew
            Method Access Control: Public

            Responsible for interfacing with the View/Controller for a Crew whose attributes are to be updated.
        */
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


        /**
            Class:                 ProjectController
            Method Name:           RemoveCrew
            Method Access Control: Public

            Responsible for interfacing with the View/Controller for a Crew that is to be removed from the Project.
        */
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


        /**
           Class:                 ProjectController
           Method Name:           ListBoxOfficeReports
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for the BoxOfficeReports in the Project and allowing the
           user to view their details.
        */
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


        /**
           Class:                 ProjectController
           Method Name:           AddBoxOfficeReport
           Method Access Control: Public

           Responsible for interfacing with the View/Controller for a new BoxOfficeReport to be added to the Project.
        */
        void ProjectController::AddBoxOfficeReport()
        {
            TrekStar::Project::BoxOfficeReport boxOfficeReport;

            BoxOfficeReportView view(boxOfficeReport);
            BoxOfficeReportController controller(boxOfficeReport, view);

            controller.AddNew();

            this->GetModel()->AddBoxOfficeReport(std::make_shared<TrekStar::Project::BoxOfficeReport>(boxOfficeReport));
        }


        /**
            Class:                 ProjectController
            Method Name:           RemoveBoxOfficeReport
            Method Access Control: Public

            Responsible for interfacing with the View/Controller for a BoxOfficeReport that is to be removed from the
            Project.
        */
        void ProjectController::RemoveBoxOfficeReport()
        {
            if ( this->GetModel()->GetBoxOfficeReports().empty() )
            {
                this->GetView()->DisplayHasNoBoxOfficeReports();
                return;
            }

            this->GetView()->PresentBoxOfficeReportsList();

            auto boxOfficeReport = this->GetModel()->GetBoxOfficeReports().at(this->GetView()->GetBoxOfficeReportSelection());
            this->GetModel()->RemoveBoxOfficeReport(boxOfficeReport);
        }


        /**
            Class:                 ProjectController
            Method Name:           ActorExists
            Method Access Control: Public

            Responsible for checking if the Project has a Crew member that matches user's search criteria for an actor
            with a specified name.
        */
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


        /**
          Class:                 ProjectController
          Method Name:           UpdateTitle
          Method Access Control: Public

          Responsible for allowing the title of the Project to be updated.
        */
        void ProjectController::UpdateTitle()
        {
            this->GetModel()->SetTitle(this->GetView()->GetNewTitle());
        }


        /**
          Class:                 ProjectController
          Method Name:           UpdateSummary
          Method Access Control: Public

          Responsible for allowing the sumary of the Project to be updated.
        */
        void ProjectController::UpdateSummary()
        {
            this->GetModel()->SetSummary(this->GetView()->GetNewSummary());
        }


        /**
          Class:                 ProjectController
          Method Name:           UpdateReleased
          Method Access Control: Public

          Responsible for allowing the released status of the Project to be updated.
        */
        void ProjectController::UpdateReleased()
        {
            this->GetModel()->SetReleased(this->GetView()->GetNewReleased());
        }


        /**
          Class:                 ProjectController
          Method Name:           UpdatePlayingInTheatres
          Method Access Control: Public

          Responsible for allowing the playing in theatres status of the Project to be updated.
        */
        void ProjectController::UpdatePlayingInTheatres()
        {
            this->GetModel()->SetPlayingInTheatres(this->GetView()->GetNewPlayingInTheatres());
        }


        /**
          Class:                 ProjectController
          Method Name:           UpdateKeyword
          Method Access Control: Public

          Responsible for allowing a keyword for the Project to be updated.
        */
        void ProjectController::UpdateKeyword()
        {
            this->GetView()->PresentKeywords();

            unsigned int keywordNo = this->GetView()->GetKeywordNo();
            this->GetModel()->SetKeyword(keywordNo, this->GetView()->GetNewKeyword(keywordNo));
        }


        /**
          Class:                 ProjectController
          Method Name:           LogMaterialAdd
          Method Access Control: Public

          Responsible for logging events where new Materials were added to the Project.
        */
        void ProjectController::LogMaterialAdd(const std::shared_ptr<Material::Material>& material)
        {
            _logger->info("Material " + std::to_string(material->GetId()) + " was added to project " + std::to_string(this->GetModel()->GetId()));
        }


        /**
           Class:                 ProjectController
           Method Name:           GetView
           Method Access Control: Protected

           Responsible for allowing access to the Projects view object.

           @return A pointer to the ProjectView object.
        */
        ProjectView* ProjectController::GetView()
        {
            return dynamic_cast<ProjectView*>(this->view);
        }


        /**
           Class:                 ProjectController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the Project interface.

           @return A pointer to the ProjectInterface object.
        */
        ProjectInterface* ProjectController::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }
    }
}
