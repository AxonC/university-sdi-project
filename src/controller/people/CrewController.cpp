#include "CrewController.h"

namespace TrekStar
{
    namespace People
    {
        /**
            Class:                 CrewController
            Method Name:           CrewController (constructor)
            Method Access Control: Public

            Constructs the Crew controller.

            @param CrewInterface object
            @param ViewInterface object
        */
        CrewController::CrewController(CrewInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }


        /**
            Class:                 CrewController
            Method Name:           ShowAll
            Method Access Control: Public

            Responsible for ordering the view to display all information for the Crew.
        */
        void CrewController::ShowAll()
        {
            this->view->PresentAll();
        }


        /**
            Class:                 CrewController
            Method Name:           ShowList
            Method Access Control: Public

            Responsible for ordering the view to display a summary list of information for the Crew.
        */
        void CrewController::ShowList()
        {
            this->view->PresentList();
        }


        /**
            Class:                 CrewController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the Crew are to be updated.
        */
        void CrewController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();

            switch ( commandInput )
            {
            case 1:
                this->UpdateName();
                break;
            case 2:
                this->UpdateJobTitle();
                break;
            default:
                break;
            }
        }


        /**
           Class:                 CrewController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new Crew.
        */
        void CrewController::AddNew()
        {
            this->UpdateName();
            this->UpdateJobTitle();
        }


        /**
           Class:                 CrewController
           Method Name:           UpdateName
           Method Access Control: Private

           Responsible for allowing the name of the crew to be updated.
        */
        void CrewController::UpdateName()
        {
            this->GetModel()->SetName(this->GetView()->GetNewName());
        }


        /**
           Class:                 CrewController
           Method Name:           UpdateJobTitle
           Method Access Control: Private

           Responsible for allowing the job title of the crew to be updated.
        */
        void CrewController::UpdateJobTitle()
        {
            this->GetModel()->SetJobTitle(this->GetView()->GetNewJobTitle());
        }


        /**
           Class:                 CrewController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the Crews view object.

           @return A pointer to the CrewView object.
        */
        CrewView* CrewController::GetView()
        {
            return dynamic_cast<CrewView*>(this->view);
        }


        /**
           Class:                 CrewController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the Crews model object.

           @return A pointer to the CrewInterface object.
        */
        CrewInterface* CrewController::GetModel()
        {
            return dynamic_cast<CrewInterface*>(this->model);
        }
    }
}