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

        void CrewView::PresentAll()
        {

        }

        void CrewView::PresentList()
        {

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

        unsigned int CrewView::GetJobTitle()
        {

        }

        CrewInterface* CrewView::GetModel()
        {
            return dynamic_cast<CrewInterface*>(this->model);
        }
    }
}