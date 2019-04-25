#include "pch.h"
#include "BoxOfficeReport.h"

namespace TrekStar
{
    namespace Project
    {
        BoxOfficeReport::BoxOfficeReport(unsigned int id, unsigned int weekNumber, double revenue, unsigned long int ticketsSold)
        {
            this->id = id;
            this->weekNumber = weekNumber;
            this->revenue = revenue;
            this->ticketsSold = ticketsSold;
        }

        SerialisedBoxOfficeReport BoxOfficeReport::ExportToSerialised() const
        {
            return {this->id, this->weekNumber, this->revenue, this->ticketsSold};
        }

        unsigned int BoxOfficeReport::GetId() const
        {
            return this->id;
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

        void to_json(json j, const SerialisedBoxOfficeReport & report)
        {
            j = json
                {
                    {"id", report.id},
                    {"weekNumber", report.weekNumber},
                    {"revenue", report.revenue},
                    {"ticketsSold", report.ticketsSold}
                };
        }

        void from_json(const json & j, SerialisedBoxOfficeReport & report)
        {
            j.at("id").get_to(report.id);
            j.at("weekNumber").get_to(report.weekNumber);
            j.at("revenue").get_to(report.revenue);
            j.at("ticketsSold").get_to(report.ticketsSold);
        }
    }
}