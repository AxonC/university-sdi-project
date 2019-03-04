#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H

#include <string>
#include <utility>
#include <vector>

#include "ProjectInterface.h"
#include "Material.h"

namespace TrekStar {
    namespace Project {
        /**
         *  Trekstar Film Project Class
         */
        class Project : public ProjectInterface
        {
            public:
                Project() = default;
                explicit Project(std::string & title);
                explicit Project(const std::string & title, const std::string & summary, bool released = false);
                ~Project();

                std::string GetSummary() const override;
                void SetSummary(std::string & contents);

                std::pair<std::string, std::string> GetTitleSummary() const;

                bool AddMaterials(Material::Material & material);
                std::vector<Material::Material> GetMaterials() const;

                void ReleaseProject();

            private:
                bool CanAddMaterial() const;

                std::string title;
                std::string summary;
                std::vector<Material::Material> materials;
                bool released{false};
                bool playingInTheatres{false};
        };
    }
}

#endif //PROJECT_PROJECT_H
