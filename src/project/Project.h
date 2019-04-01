#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>

#include "../material/Material.h"
#include "../people/Crew.h"

namespace TrekStar {
    namespace Project {
        /**
         *  Trekstar Film Project Class
         */
        class Project
        {
        public:
            Project() = default;
            explicit Project(std::string title, std::string summary, bool released, bool playingInTheatres);
            explicit Project(std::string & title);
            explicit Project(const std::string & title, const std::string & summary, bool released = false);
            ~Project();

            std::string GetTitle() const;

            std::string GetSummary() const;
            bool GetReleased() const;
            bool GetPlayingInTheatres() const;
            void SetSummary(const std::string & contents);

            std::pair<std::string, std::string> GetTitleSummary() const;

            void AddMaterials(const std::vector<std::shared_ptr<Material::Material>> & materials);
            bool AddMaterials(const std::shared_ptr<Material::Material> & material);
            std::vector<std::shared_ptr<Material::Material>> GetMaterials() const;
            void RemoveMaterial(const std::shared_ptr<Material::Material> & material);

            std::vector<std::shared_ptr<People::Crew>> GetCrew() const;
            void AddCrew(const std::shared_ptr<People::Crew> &);
            void RemoveCrew(const std::shared_ptr<People::Crew> &);

            void ReleaseProject();

        private:
            bool CanAddMaterial() const;

            std::string title;
            std::string summary;
            std::vector<std::shared_ptr<Material::Material>> materials;
            std::vector<std::shared_ptr<People::Crew>> crew;
            bool released{false};
            bool playingInTheatres{false};
        };
    }
}

#endif //PROJECT_PROJECT_H
