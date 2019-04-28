#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H

#include "ProjectInterface.h"

using json = nlohmann::json;

namespace TrekStar
{
    namespace People
    {
        class Crew;
        class SerializedCrew;
    } // namespace People

    namespace Material
    {
        class Material;
    } // namespace Material

    namespace Project
    {
        class BoxOfficeReport;
    } // namespace Project
} // namespace TrekStar

namespace TrekStar
{
    namespace Project
    {
        struct SerialisedProject
        {
            unsigned int id;
            std::string title;
            std::string summary;
            bool released;
            bool playingInTheatres;
            std::vector<std::string> keywords;
            std::vector<std::shared_ptr<People::Crew>> crew;
            std::vector<std::shared_ptr<BoxOfficeReport>> boxOfficeReports;
        };

        /**
         *  Trekstar Film Project Class
         */
        class Project: public ProjectInterface
        {
        private:
            unsigned int id{0};
            std::string title;
            std::string searchableTitle;                                  // for searching
            std::string summary;
            std::vector<std::shared_ptr<Material::Material>> materials;
            std::vector<std::string> materialFormats;                    // holds only the format of each material
            bool released = false;
            bool playingInTheatres = false;
            std::vector<std::string> keywords;
            std::vector<std::shared_ptr<People::Crew>> crew;
            std::vector<std::shared_ptr<BoxOfficeReport>> boxOfficeReports;
            bool MaterialFormatExists(const std::string & materialFormat) const;
            void AddMaterialFormat(const std::string & materialFormat);

        public:
            Project() = default;
            Project(const std::string & title, const std::string & summary, bool released, bool playingInTheatres, const std::vector<std::string> & keywords);
            explicit Project(const SerialisedProject & project);
            ~Project() final;

            unsigned int GetId() const override;
            std::string GetTitle() const override;
            std::string GetSearchableTitle() const;
            std::string GetSummary() const override;
            std::vector<std::shared_ptr<Material::Material>> GetMaterials() const override;
            bool GetReleased() const override;
            bool GetPlayingInTheatres() const override;
            std::vector<std::string> GetKeywords() const override;
            std::vector<std::string> GetMaterialFormats() const override;

            void SetTitle(const std::string & title) override;
            void SetSummary(const std::string & summary) override;
            void SetReleased(const bool & released) override;
            void SetPlayingInTheatres(const bool & playingInTheatres) override;
            void SetKeyword(const unsigned int & keywordNo, const std::string & keyword) override;

            void AddMaterials(const std::vector<std::shared_ptr<Material::Material>> & materials);
            void AddMaterial(const std::shared_ptr<Material::Material> & material) override;
            void RemoveMaterial(const std::shared_ptr<Material::Material> & material) override;
            bool CanAddMaterial() const override;

            std::vector<std::shared_ptr<People::Crew>> GetCrew() const override;
            void AddCrew(const std::shared_ptr<People::Crew> &) override;
            void AddCrew(const std::vector<std::shared_ptr<People::Crew>> & crew);
            void RemoveCrew(const std::shared_ptr<People::Crew> &) override;
            std::shared_ptr<People::Crew> FindActor(std::string &) override;

            std::vector<std::shared_ptr<BoxOfficeReport>> GetBoxOfficeReports() const override;
            void AddBoxOfficeReport(const std::shared_ptr<BoxOfficeReport> &) override;
            void AddBoxOfficeReports(const std::vector<std::shared_ptr<BoxOfficeReport>> &) override;
            unsigned long long int GetTotalBoxOfficeRevenue() const override;
            void RemoveBoxOfficeReport(const std::shared_ptr<BoxOfficeReport> &) override;

            void ReleaseProject();

            SerialisedProject ExportToSerialised() const;

            bool operator>(const Project & project) const;
            bool operator<(const Project & project) const;
            bool operator>=(const Project & project) const;
            bool operator<=(const Project & project) const;

            bool operator==(unsigned int id) const;
            bool operator==(const std::string & title) const;
            bool operator<(const std::string & title) const;
        };

        void to_json(json & j, const SerialisedProject & project);
        void from_json(const json & json, SerialisedProject & project);
    }
}

#endif //PROJECT_PROJECT_H
