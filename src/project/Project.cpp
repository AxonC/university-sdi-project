#include "Project.h"

namespace TrekStar
{
    namespace Project
    {
        Project::Project(const std::string & title, const std::string & summary, bool released, bool playingInTheatres, const std::vector<std::string> & keywords)
        {
            this->title = title;
            this->summary = summary;
            this->released = released;
            this->playingInTheatres = playingInTheatres;
            this->keywords = keywords;
        }

        Project::Project(const SerialisedProject & project)
        {
            this->id = project.id;
            this->title = project.title;
            this->summary = project.summary;
            this->released = project.released;
            this->playingInTheatres = project.playingInTheatres;
            this->keywords = project.keywords;
        }

        Project::~Project() = default;

        unsigned int Project::GetId() const
        {
            return this->id;
        }

        std::string Project::GetTitle() const
        {
            return this->title;
        }

        std::string Project::GetSummary() const
        {
            return this->summary;
        }

        std::vector<std::shared_ptr<Material::Material>> Project::GetMaterials() const
        {
            return materials;
        }

        bool Project::GetReleased() const
        {
            return this->released;
        }

        bool Project::GetPlayingInTheatres() const
        {
            return this->playingInTheatres;
        }

        std::pair<std::string, std::string> Project::GetTitleSummary() const
        {
            return {this->title, this->GetSummary()};
        }

        void Project::AddMaterials(const std::vector<std::shared_ptr<Material::Material>> & materials)
        {
            if ( !this->CanAddMaterial() )
            {
                throw std::domain_error("Material cannot be added.");
            }

            for ( const auto &material: materials )
            {
                this->materials.push_back(material);
            }
        }

        bool Project::AddMaterials(const std::shared_ptr<Material::Material> & material)
        {
            if ( !this->CanAddMaterial() )
            {
                return false;
            }

            materials.push_back(material);

            return true;
        }

        void Project::RemoveMaterial(const std::shared_ptr<Material::Material> & material)
        {
            auto search = std::find(materials.begin(), materials.end(), material);

            if ( search == materials.end() )
            {
                throw std::out_of_range("Material not found.");
            }

            materials.erase(search);
        }

        std::vector<std::shared_ptr<People::Crew>> Project::GetCrew() const
        {
            return this->crew;
        }

        void Project::AddCrew(const std::shared_ptr<TrekStar::People::Crew> & crewMember)
        {
            this->crew.push_back(crewMember);
        }

        void Project::AddCrew(const std::vector<std::shared_ptr<Crew>> &crew)
        {
            for ( const auto & crewMember: crew )
            {
                this->crew.push_back(crewMember);
            }
        }

        void Project::RemoveCrew(const std::shared_ptr<TrekStar::People::Crew> & crewMember)
        {
            auto search = std::find(crew.begin(), crew.end(), crewMember);

            if ( search == crew.end() )
            {
                throw std::out_of_range("Crew Member not found.");
            }

            crew.erase(search);
        }

        void Project::ReleaseProject()
        {
            this->released = true;
        }

        SerialisedProject Project::ExportToSerialised() const
        {
            return SerialisedProject
                {
                    this->id,
                    this->title,
                    this->summary,
                    this->released,
                    this->playingInTheatres,
                    this->keywords
                };
        }

        bool Project::CanAddMaterial() const
        {
            return this->released && !this->playingInTheatres;
        }

        void to_json(json & j, const SerialisedProject & project)
        {
            j = json
                {
                    {"id", project.id},
                    {"title", project.title},
                    {"summary", project.summary},
                    {"released", project.released},
                    {"playingInTheatres", project.playingInTheatres},
                    {"keywords", project.keywords}
                };
        }

        void from_json(const json & json, SerialisedProject & project)
        {
            json.at("id").get_to(project.id);
            json.at("title").get_to(project.title);
            json.at("summary").get_to(project.summary);
            json.at("released").get_to(project.released);
            json.at("playingInTheatres").get_to(project.playingInTheatres);
            json.at("keywords").get_to(project.keywords);
        }
    }
}

