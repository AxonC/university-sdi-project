#include "pch.h"

#include "BoxOfficeReportController.h"

namespace TrekStar
{
    namespace Project
    {
        /**
            Class:                 BoxOfficeReportController
            Method Name:           BoxOfficeReportController (constructor)
            Method Access Control: Public

            Constructs the BoxOfficeReport controller.

            @param BoxOfficeReport object
            @param ViewInterface object
        */
        BoxOfficeReportController::BoxOfficeReportController(BoxOfficeReportInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }


        /**
            Class:                 BoxOfficeReportController
            Method Name:           ShowAll
            Method Access Control: Public

            Responsible for ordering the view to display all information for the BoxOfficeReport.
        */
        void BoxOfficeReportController::ShowAll()
        {
            this->view->PresentAll();
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           ShowList
           Method Access Control: Public

           Responsible for ordering the view to display a summary list of information for the BoxOfficeReport.
        */
        void BoxOfficeReportController::ShowList()
        {
            this->view->PresentList();
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new BoxOfficeReport.
        */
        void BoxOfficeReportController::AddNew()
        {
            this->AddWeekNumber();
            this->AddRevenue();
            this->AddTicketsSold();
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           AddSideOneAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing a week number to be added to the BoxOfficeReport.
        */
        void BoxOfficeReportController::AddWeekNumber()
        {
            this->GetModel()->SetWeekNumber(this->GetView()->GetNewWeekNumber());
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           AddSideOneAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing revenue to be added to the BoxOfficeReport.
        */
        void BoxOfficeReportController::AddRevenue()
        {
            this->GetModel()->SetRevenue(this->GetView()->GetNewRevenue());
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           AddSideOneAdditionalLanguageTracks
           Method Access Control: Private

           Responsible for allowing tickets sold to be added to the BoxOfficeReport.
        */
        void BoxOfficeReportController::AddTicketsSold()
        {
            this->GetModel()->SetTicketsSold(this->GetView()->GetNewTicketsSold());
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           GetView
           Method Access Control: Private

           Responsible for allowing access to the BoxOfficeReports view object.

           @return A pointer to the BoxOfficeReportView object.
        */
        BoxOfficeReportView* BoxOfficeReportController::GetView()
        {
            return dynamic_cast<BoxOfficeReportView*>(this->view);
        }


        /**
           Class:                 BoxOfficeReportController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the BoxOfficeReports model object.

           @return A pointer to the BoxOfficeReportInterface object.
        */
        BoxOfficeReportInterface* BoxOfficeReportController::GetModel()
        {
            return dynamic_cast<BoxOfficeReportInterface*>(this->model);
        }

    }
}
