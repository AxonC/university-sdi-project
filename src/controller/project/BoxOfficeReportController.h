#ifndef TREKSTAR_BOXOFFICEREPORTCONTROLLER_H
#define TREKSTAR_BOXOFFICEREPORTCONTROLLER_H

#include "../../model/project/BoxOfficeReport.h"
#include "../../view/project/BoxOfficeReportView.h"
#include "../../model/project/BoxOfficeReportInterface.h"
#include "../BaseController.h"

namespace TrekStar
{
    namespace Project
    {
        class BoxOfficeReportController : public BaseController
        {
        public:
            BoxOfficeReportController() = default;
            BoxOfficeReportController(BoxOfficeReportInterface & model, ViewInterface & view);
            ~BoxOfficeReportController() = default;

            void ShowAll() override;
            void ShowList() override;

            void AddNew();

        private:
            void AddWeekNumber();
            void AddRevenue();
            void AddTicketsSold();

            BoxOfficeReportInterface* GetModel();
            BoxOfficeReportView* GetView();
        };
    }
}

#endif //TREKSTAR_BOXOFFICEREPORTCONTROLLER_H
