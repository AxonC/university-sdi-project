#include "CrewView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace People
    {
        CrewView::CrewView(CrewInterface & model) : BaseView()
        {
            this->model = &model;
        }

        void CrewView::PresentAll() {}

        void CrewView::PresentList() {}

        unsigned int CrewView::GetUpdateOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Edit Name"},
                            {2, "Edit Job Title"},
                            {3, "Cancel"}
                    },
                    "Update Crew"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        std::string CrewView::GetNewName()
        {
            std::string currentName = this->GetModel()->GetName();

            if ( currentName.empty() )
            {
                std::cout << "Name: ";
            }
            else
            {
                std::cout << "Name [current: " << currentName << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        std::string CrewView::GetNewJobTitle()
        {
            std::string currentJobTitle = this->GetModel()->GetJobTitle();

            if ( currentJobTitle.empty() )
            {
                std::cout << "Job Title: ";
            }
            else
            {
                std::cout << "Job Title [current: " << currentJobTitle << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        CrewInterface* CrewView::GetModel()
        {
            return dynamic_cast<CrewInterface*>(this->model);
        }
    }
}