#ifndef TREKSTAR_BOXOFFICEREPORT_H
#define TREKSTAR_BOXOFFICEREPORT_H

#include "BoxOfficeReportInterface.h"

using json = nlohmann::json;

namespace TrekStar
{
    namespace Project
    {
        struct SerialisedBoxOfficeReport
        {
            unsigned int weekNumber;
            double revenue;
            unsigned long int ticketsSold;
        };

        class BoxOfficeReport : public BoxOfficeReportInterface
        {
        public:
            BoxOfficeReport() = default;
            BoxOfficeReport(unsigned int weekNumber, double revenue, unsigned long int ticketsSold);
            explicit BoxOfficeReport(const SerialisedBoxOfficeReport & report);
            ~BoxOfficeReport() = default;

            SerialisedBoxOfficeReport ExportToSerialised() const;

            unsigned int GetWeekNumber() const override;
            double GetRevenue() const override;
            unsigned long int GetTicketsSold() const override;

            void SetWeekNumber(unsigned int weekNumber) override;
            void SetRevenue(double revenue) override;
            void SetTicketsSold(unsigned long int ticketsSold) override;

        private:
            unsigned int weekNumber;
            double revenue;
            unsigned long int ticketsSold;
        };

        void to_json(json j, const SerialisedBoxOfficeReport & report);
        void from_json(const json & j, SerialisedBoxOfficeReport & report);
    }
}

#endif //TREKSTAR_BOXOFFICEREPORT_H
