#ifndef TREKSTAR_BOXOFFICEREPORT_H
#define TREKSTAR_BOXOFFICEREPORT_H

using json = nlohmann::json;

namespace TrekStar
{
    namespace Project
    {
        struct SerialisedBoxOfficeReport
        {
            unsigned int id;
            unsigned int weekNumber;
            double revenue;
            unsigned long int ticketsSold;
        };

        class BoxOfficeReport
        {
        public:
            BoxOfficeReport() = default;
            explicit BoxOfficeReport(unsigned int id, unsigned int weekNumber, double revenue, unsigned long int ticketsSold);
            ~BoxOfficeReport() = default;

            SerialisedBoxOfficeReport ExportToSerialised() const;
        private:
            unsigned int id;
            unsigned int weekNumber;
            double revenue;
            unsigned long int ticketsSold;
        };

        void to_json(json j, const SerialisedBoxOfficeReport & report);
        void from_json(const json & j, SerialisedBoxOfficeReport & report);
    }
}

#endif //TREKSTAR_BOXOFFICEREPORT_H
