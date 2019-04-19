#ifndef TREKSTAR_CREW_H
#define TREKSTAR_CREW_H

#include <string>
#include "../../lib/json.hpp"

using json = nlohmann::json;

namespace TrekStar
{
    namespace People
    {
        struct SerializedCrew
        {
            unsigned int id;
            std::string name;
            std::string jobTitle;
        };

        class Crew
        {
        protected:
            unsigned int id;
            std::string name;
            std::string jobTitle;

        public:
            Crew() = default;
            explicit Crew(const SerializedCrew & crew);
            Crew(unsigned int id, const std::string & name, const std::string & jobTitle);
            virtual ~Crew() = default;

            std::string GetName();

            void SetJobTitle(const std::string &);

            SerializedCrew ExportToSerialized() const;
        };

        json to_json(const SerializedCrew & crew);
        void from_json(const json & json, SerializedCrew & crew);
    }
}

#endif //TREKSTAR_CREW_H