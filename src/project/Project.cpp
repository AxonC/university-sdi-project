#include <iostream>
#include <algorithm>
#include <sstream>     // for std::stringstream

#include "Project.h"

namespace TrekStar {
    namespace Project {
        Project::Project(std::string title, std::string summary, bool released, bool playingInTheatres)
        {
            this->title = title;
            this->summary = summary;
            this->released = released;
            this->playingInTheatres = playingInTheatres;
        }

        void AddMaterials(std::shared_ptr<Material::Material> materials)
        {
            this->materials = materials;
        }

        Project::Project(std::string & title)
        {
            this->title = title;
            materials = {};
        }

        Project::Project(const std::string & name, const std::string & summary, bool released)
        {
            this->title = name;
            this->summary = summary;
            this->released = released;
        }

        Project::~Project() = default;

        std::string Project::GetTitle() const
        {
            return this->title;
        }

        std::string Project::GetSummary() const
        {
            return this->summary;
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

        bool Project::CanAddMaterial() const
        {
            return this->released && !this->playingInTheatres;
        }

        bool Project::AddMaterials(Material::Material & material)
        {
            if (!this->CanAddMaterial()) {
                return false;
            }

            materials.push_back(material);

            return true;
        }

        void Project::RemoveMaterial(Material::Material &material)
        {
            auto search = std::find(materials.begin(), materials.end(), material);

            if(search == materials.end()) {
                throw std::out_of_range("Material not found.");
            }

            materials.erase(search);
        }

        std::vector<Material::Material> Project::GetMaterials() const
        {
            return materials;
        }

        void Project::ReleaseProject()
        {
            this->released = true;
        }
    }
}

