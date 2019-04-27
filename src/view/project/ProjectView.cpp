#include <iostream>

#include "ProjectView.h"
#include "../material/MaterialView.h"
#include "../../controller/material/MaterialController.h"
#include "../people/CrewView.h"
#include "../../controller/people/CrewController.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"
#include "../../information/SequentialBrowser.h"

using TrekStar::Material::MaterialController;
using TrekStar::Material::MaterialView;
using TrekStar::People::CrewController;
using TrekStar::People::CrewView;

namespace TrekStar
{
    namespace Project
    {
        ProjectView::ProjectView(ProjectInterface & model) : BaseView()
        {
            this->model = &model;
        }

        void ProjectView::PresentAll()
        {
            auto model = this->GetModel();

            std::string released = "no";
            std::string playingInTheatres = "no";

            if ( model->GetReleased() )
            {
                released = "yes";
            }

            if ( model->GetPlayingInTheatres() )
            {
                playingInTheatres = "yes";
            }

            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Project " << std::to_string(model->GetId()) << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Title               : " << model->GetTitle() << std::endl;
            std::cout << "Summary             : " << model->GetSummary() << std::endl;
            std::cout << "Released            : " << released << std::endl;
            std::cout << "Playing in theatres : " << playingInTheatres << std::endl;

            std::cout << "Keywords            : ";
            if ( model->GetKeywords().empty() )
            {
                std::cout << "No keywords...";
            }
            else
            {
                this->DisplayVectorAsCSV(model->GetKeywords());
            }
            std::cout << std::endl;

            std::cout << "Available on        : ";
            if ( model->GetMaterialFormats().empty() )
            {
                std::cout << "No material formats...";
            }
            else
            {
                this->DisplayVectorAsCSV(model->GetMaterialFormats());
            }
            std::cout << std::endl;
        }

        void ProjectView::PresentList()
        {
            auto model = this->GetModel();

            std::cout << "Title: " << model->GetTitle() << std::endl;
        }

        void ProjectView::PresentKeywords()
        {
            unsigned int counter = 0;
            for ( const auto & keyword: this->GetModel()->GetKeywords() )
            {
                counter++;
                std::cout << "Keyword #" << counter << ": " << keyword << std::endl;
            }
        }

        void ProjectView::PresentMaterialsList()
        {
            unsigned int counter = 0;
            for ( const auto & material: this->GetModel()->GetMaterials() )
            {
                counter++;
                std::cout << "[" << counter << "]: ";
                MaterialView view(*material);
                MaterialController controller(*material, view);

                controller.ShowList();
            }
        }

        void ProjectView::PresentCrewList()
        {
            unsigned int counter = 0;
            for ( const auto & crew: this->GetModel()->GetCrew() )
            {
                counter++;
                std::cout << "[" << counter << "]: ";
                CrewView view(*crew);
                CrewController controller(*crew, view);

                controller.ShowList();
            }
        }

        std::string ProjectView::GetNewTitle()
        {
            std::string currentTitle = this->GetModel()->GetTitle();

            if ( currentTitle.empty() )
            {
                std::cout << "Title: ";
            }
            else
            {
                std::cout << "Title [current: " << currentTitle << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        std::string ProjectView::GetNewSummary()
        {
            std::string currentSummary = this->GetModel()->GetSummary();

            if ( currentSummary.empty() )
            {
                std::cout << "Summary: ";
            }
            else
            {
                std::cout << "Summary [current: " << currentSummary << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        bool ProjectView::GetNewReleased()
        {
            std::string released = "no";
            if ( this->GetModel()->GetReleased() )
            {
                released = "yes";
            }

            std::cout << "Released [current: " << released << "]: ";
            return TrekStar::Command::GetBoolInput();
        }

        bool ProjectView::GetNewPlayingInTheatres()
        {
            std::string playingInTheatres = "no";
            if ( this->GetModel()->GetPlayingInTheatres() )
            {
                playingInTheatres = "yes";
            }

            std::cout << "Playing In Theatres [current: " << playingInTheatres << "]: ";
            return TrekStar::Command::GetBoolInput();
        }

        unsigned int ProjectView::GetKeywordNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetKeywords().size(), "Keyword");
        }

        std::string ProjectView::GetNewKeyword(const unsigned int & keywordNo)
        {
            std::cout << "Keyword #" << keywordNo + 1 << " [current: " << this->GetModel()->GetKeywords().at(keywordNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string ProjectView::GetNewMaterialFormat()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "DVD"},
                            {2, "Double Sided DVD"},
                            {3, "Bluray"},
                            {4, "VHS"},
                            {5, "Box Set"}
                    },
                    "Material Format: "
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            switch ( commandInput )
            {
            case 1:
                return "dvd";
            case 2:
                return "dsdvd";
            case 3:
                return "bluray";
            case 4:
                return "vhs";
            case 5:
                return "boxset";
            default:
                return "dvd";
            }
        }

        unsigned int ProjectView::GetUpdateOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Edit Title"},
                            {2, "Edit Summary"},
                            {3, "Edit Released"},
                            {4, "Edit Playing In Theatres"},
                            {5, "Edit Existing Keywords"},
                            {6, "Edit Crew"},
                            {7, "Cancel"}
                    },
                    "Update Project"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int ProjectView::GetMaterialSelection()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetMaterials().size(), "Material ID");
        }

        unsigned int ProjectView::GetCrewSelection()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetCrew().size(), "Crew ID");
        }

        unsigned int ProjectView::GetListMaterialsOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Next Material"},
                            {2, "Previous Material"},
                            {3, "Cancel"}
                    },
                    "List Materials"
            );

            commandHandler.displayCommands();
            unsigned int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int ProjectView::GetCurrentMaterial(unsigned int currentMaterial, unsigned int commandInput)
        {
            TrekStar::Information::SequentialBrowser sequentialBrowser(this->GetModel()->GetMaterials().size(), currentMaterial, commandInput);

            return sequentialBrowser.GetItemNumber();
        }

        unsigned int ProjectView::GetListCrewOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Next Crew"},
                            {2, "Previous Crew"},
                            {3, "Cancel"}
                    },
                    "List Crew"
            );

            commandHandler.displayCommands();
            unsigned int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int ProjectView::GetCurrentCrew(unsigned int currentCrew, unsigned int commandInput)
        {
            TrekStar::Information::SequentialBrowser sequentialBrowser(this->GetModel()->GetCrew().size(), currentCrew, commandInput);

            return sequentialBrowser.GetItemNumber();
        }

        unsigned int ProjectView::GetListBoxOfficeReportsOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Next Box Office Report"},
                            {2, "Previous Box Office Report"},
                            {3, "Cancel"}
                    },
                    "List Box Office Reports"
            );

            commandHandler.displayCommands();
            unsigned int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int ProjectView::GetCurrentBoxOfficeReport(unsigned int currentBoxOfficeReport, unsigned int commandInput)
        {
            TrekStar::Information::SequentialBrowser sequentialBrowser(this->GetModel()->GetBoxOfficeReports().size(), currentBoxOfficeReport, commandInput);

            return sequentialBrowser.GetItemNumber();
        }

        void ProjectView::DisplayCannotAddMaterial()
        {
            std::cout << "Material cannot be added to this Project." << std::endl;
        }

        void ProjectView::DisplayHasNoMaterials()
        {
            std::cout << "This project has no materials to display." << std::endl;
        }

        void ProjectView::DisplayHasNoCrew()
        {
            std::cout << "This project has no crew members to display." << std::endl;
        }

        void ProjectView::DisplayHasNoBoxOfficeReports()
        {
            std::cout << "This project has no box office reports to display." << std::endl;
        }

        ProjectInterface* ProjectView::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }

        void ProjectView::DisplayVectorAsCSV(const std::vector<std::string> & stringVector)
        {
            if ( !stringVector.empty() )
            {
                std::copy(std::begin(stringVector), std::prev(std::end(stringVector)), std::ostream_iterator<std::string>(std::cout, ", "));
                std::cout << stringVector.back();
            }
        }
    }
}
