#include "pch.h"
#include "BoxOfficeReport.h"

namespace TrekStar
{
    namespace Project
    {
        BoxOfficeReport::BoxOfficeReport(unsigned int weekNumber, double revenue, unsigned long int ticketsSold)
        {
            this->weekNumber = weekNumber;
            this->revenue = revenue;
            this->ticketsSold = ticketsSold;
        }

        BoxOfficeReport::BoxOfficeReport(const SerialisedBoxOfficeReport &report)
        {
            this->weekNumber = report.weekNumber;
            this->revenue = report.revenue;
            this->ticketsSold = report.ticketsSold;
        }

        SerialisedBoxOfficeReport BoxOfficeReport::ExportToSerialised() const
        {
            return {this->weekNumber, this->revenue, this->ticketsSold};
        }

        unsigned int BoxOfficeReport::GetWeekNumber() const
        {
            return this->weekNumber;
        }

        double BoxOfficeReport::GetRevenue() const
        {
            return this->revenue;
        }

        unsigned long int BoxOfficeReport::GetTicketsSold() const
        {
            return this->ticketsSold;
        }

        void BoxOfficeReport::SetWeekNumber(unsigned int weekNumber)
        {
            this->weekNumber = weekNumber;
        }

        void BoxOfficeReport::SetRevenue(double revenue)
        {
            this->revenue = revenue;
        }

        void BoxOfficeReport::SetTicketsSold(unsigned long int ticketsSold)
        {
            this->ticketsSold = ticketsSold;
        }

        void to_json(json j, const SerialisedBoxOfficeReport & report)
        {
            j = json
                {
                    {"weekNumber", report.weekNumber},
                    {"revenue", report.revenue},
                    {"ticketsSold", report.ticketsSold}
                };
        }

        void from_json(const json & j, SerialisedBoxOfficeReport & report)
        {
            j.at("weekNumber").get_to(report.weekNumber);
            j.at("revenue").get_to(report.revenue);
            j.at("ticketsSold").get_to(report.ticketsSold);
        }
    }
}