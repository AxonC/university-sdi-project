#ifndef TREKSTAR_CREW_H
#define TREKSTAR_CREW_H

#include <string>
#include "../lib/json.hpp"

using json = nlohmann::json;

namespace TrekStar {
    namespace People {
        struct SerializedCrew {
            unsigned int id;
            std::string name;
            std::string jobTitle;
        };

        class Crew
        {
        public:
            Crew() = default;
            explicit Crew(const SerializedCrew & crew);
            Crew(unsigned int id, const std::string & name, const std::string & jobTitle);
            virtual ~Crew() = default;

            void SetJobTitle(const std::string &);

            std::string GetName();
            std::string skup();

            SerializedCrew ExportToSerialized() const;

        protected:
            unsigned int id;
            std::string name;
            std::string jobTitle;
        };

        json to_json(const SerializedCrew & crew);
        void from_json(const json & json, SerializedCrew & crew);
    }
}

#endif //TREKSTAR_CREW_H
