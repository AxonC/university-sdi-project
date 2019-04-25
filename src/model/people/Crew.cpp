#include "pch.h"
#include "Crew.h"

namespace TrekStar
{
    namespace People
    {
        Crew::Crew(const SerializedCrew &crew)
        {
            this->id = crew.id;
            this->name = crew.name;
            this->jobTitle = crew.jobTitle;
        }

        Crew::Crew(unsigned int id, const std::string & name, const std::string & jobTitle)
        {
            this->id = id;
            this->name = name;
            this->jobTitle = jobTitle;
        }

        std::string Crew::GetName() const
        {
            return this->name;
        }

        std::string Crew::GetJobTitle() const
        {
            return this->jobTitle;
        };

        void Crew::SetName(const std::string & name)
        {
            this->name = name;
        }

        void Crew::SetJobTitle(const std::string & title)
        {
            this->jobTitle = title;
        }

        SerializedCrew Crew::ExportToSerialized() const
        {
            return
                {
                    this->id,
                    this->name,
                    this->jobTitle
                };
        }

        void to_json(json & j, const SerializedCrew &crew)
        {
            j = json
                {
                    {"id", crew.id},
                    {"name", crew.name},
                    {"jobTitle", crew.jobTitle}
                };
        }

        void from_json(const json &json, SerializedCrew & crew)
        {
            json.at("id").get_to(crew.id);
            json.at("name").get_to(crew.name);
            json.at("jobTitle").get_to(crew.jobTitle);
        }
    }
}