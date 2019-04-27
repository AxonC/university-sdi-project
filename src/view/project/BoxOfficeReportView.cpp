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
            std::cout << "Box Office Report " << std::to_string(model->GetId()) << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Week Number         : " << model->GetWeekNumber() << std::endl;
            std::cout << "Revenue             : " << model->GetRevenue() << std::endl;
            std::cout << "Tickets Sold        : " << model->GetTicketsSold() << std::endl;
        }

        void BoxOfficeReportView::PresentList()
        {
            std::cout << "Week Number: " << this->GetModel()->GetWeekNumber() << std::endl;
        }

        double BoxOfficeReportView::GetNewRevenue()
        {
            std::cout << "Revenue: ";

            return TrekStar::Command::GetDoubleInput();
        }

        BoxOfficeReportInterface* BoxOfficeReportView::GetModel()
        {
            return dynamic_cast<BoxOfficeReportInterface*>(this->model);
        }
    }
}