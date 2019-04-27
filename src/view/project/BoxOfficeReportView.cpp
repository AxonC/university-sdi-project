#include "BoxOfficeReportView.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace Project
    {
        BoxOfficeReportView::BoxOfficeReportView(BoxOfficeReportInterface & model) : BaseView()
        {
            this->model = &model;
        }

        void BoxOfficeReportView::PresentAll()
        {
            auto model = this->GetModel();

            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Box Office Report for Week Number " << std::to_string(model->GetWeekNumber()) << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Revenue             : " << model->GetRevenue() << std::endl;
            std::cout << "Tickets Sold        : " << model->GetTicketsSold() << std::endl;
        }

        void BoxOfficeReportView::PresentList()
        {
            std::cout << "Week Number: " << this->GetModel()->GetWeekNumber() << std::endl;
        }

        int BoxOfficeReportView::GetNewWeekNumber()
        {
            std::cout << "Week Number: ";

            return TrekStar::Command::GetIntInput();
        }

        double BoxOfficeReportView::GetNewRevenue()
        {
            std::cout << "Revenue: ";

            return TrekStar::Command::GetDoubleInput();
        }

        unsigned long int BoxOfficeReportView::GetNewTicketsSold()
        {
            std::cout << "Tickets Sold: ";

            return TrekStar::Command::GetUnsignedLongIntInput();
        }

        BoxOfficeReportInterface* BoxOfficeReportView::GetModel()
        {
            return dynamic_cast<BoxOfficeReportInterface*>(this->model);
        }
    }
}
