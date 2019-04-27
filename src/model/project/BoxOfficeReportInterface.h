#ifndef TREKSTAR_BOXOFFICEREPORTINTERFACE_H
#define TREKSTAR_BOXOFFICEREPORTINTERFACE_H

#include "../Model.h"

namespace TrekStar
{
    namespace Project
    {
        class BoxOfficeReportInterface : public TrekStar::Model
        {
        public:
            ~BoxOfficeReportInterface() override = default;

            virtual unsigned int GetWeekNumber() const = 0;
            virtual double GetRevenue() const = 0;
            virtual unsigned long int GetTicketsSold() const = 0;

            virtual void SetWeekNumber(unsigned int weekNumber) = 0;
            virtual void SetRevenue(double revenue) = 0;
            virtual void SetTicketsSold(unsigned long int ticketsSold) = 0;
        };
    }
}

#endif //TREKSTAR_BOXOFFICEREPORTINTERFACE_H
