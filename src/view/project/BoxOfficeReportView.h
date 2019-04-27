#ifndef TREKSTAR_BOXOFFICEREPORTVIEW_H
#define TREKSTAR_BOXOFFICEREPORTVIEW_H

#include "../BaseView.h"
#include "../../model/project/BoxOfficeReportInterface.h"

using TrekStar::View::BaseView;

namespace TrekStar
{
    namespace Project
    {
        class BoxOfficeReportView : public BaseView
        {
        public:
            BoxOfficeReportView() = default;
            explicit BoxOfficeReportView(BoxOfficeReportInterface & model);

            void PresentAll() override;
            void PresentList() override;

            double GetNewRevenue();
            unsigned long int GetNewTicketsSold();

            BoxOfficeReportInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_BOXOFFICEREPORTVIEW_H
