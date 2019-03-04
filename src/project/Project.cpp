//
// Created by Callum Axon on 2019-02-27
//

#include "Project.h"

namespace TrekStar {
    namespace Project {
        Project::Project(std::string & title)
        {
            this->title = title;
            materials = {};

        }

        Project::Project(std::string & name, std::string & summary, bool released)
        {
            this->title = name;
            this->summary = summary;
            this->released = released;
        }

        std::string Project::GetSummary() const
        {
            return this->summary;
        }

        std::pair<std::string, std::string> Project::GetTitleSummary() const
        {
            return {this->title, this->GetSummary()};
        }

        bool Project::CanAddMaterial() const {
            return released;
        }

        bool Project::AddMaterials(Material::Material & material) {
            if (!this->CanAddMaterial()) {
                return false;
            }

            materials.push_back(material);

            return true;
        }

        std::vector<Material::Material> Project::GetMaterials() const {
            return materials;
        }

        void Project::ReleaseProject() {
            this->released = true;
        }

        Project::~Project() = default;
    }
}

