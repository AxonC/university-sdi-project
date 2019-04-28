#ifndef TREKSTAR_PROJECTINTERFACE_H
#define TREKSTAR_PROJECTINTERFACE_H

#include "../Model.h"

#include "BoxOfficeReport.h"

namespace TrekStar
{
    namespace Material
    {
        class Material;
    } // namespace Material
} // namespace TrekStar

namespace TrekStar
{
    namespace People
    {
        class Crew;
    } // namespace People
} // namespace TrekStar

namespace TrekStar
{
    namespace Project
    {
        class ProjectInterface : public TrekStar::Model
        {
        public:
            ~ProjectInterface() override = default;
            virtual unsigned int GetId() const = 0;
            virtual std::string GetTitle() const = 0;
            virtual std::string GetSummary() const = 0;
            virtual std::vector<std::shared_ptr<Material::Material>> GetMaterials() const = 0;
            virtual bool GetReleased() const = 0;
            virtual bool GetPlayingInTheatres() const = 0;
            virtual std::vector<std::string> GetKeywords() const = 0;
            virtual std::vector<std::string> GetMaterialFormats() const = 0;

            virtual void SetTitle(const std::string & title) = 0;
            virtual void SetSummary(const std::string & summary) = 0;
            virtual void SetReleased(const bool & released) = 0;
            virtual void SetPlayingInTheatres(const bool & playingInTheatres) = 0;
            virtual void SetKeywords(const std::vector<std::string> & keywords) = 0;
            virtual void SetKeyword(const unsigned int & keywordNo, const std::string & keyword) = 0;

            virtual std::vector<std::shared_ptr<People::Crew>> GetCrew() const = 0;

            virtual void AddMaterial(const std::shared_ptr<Material::Material> & material) = 0;
            virtual void RemoveMaterial(const std::shared_ptr<Material::Material> & material) = 0;
            virtual bool CanAddMaterial() const = 0;

            virtual void AddCrew(const std::shared_ptr<People::Crew> &) = 0;
            virtual void RemoveCrew(const std::shared_ptr<People::Crew> &) = 0;

            virtual std::vector<std::shared_ptr<BoxOfficeReport>> GetBoxOfficeReports() const = 0;
            virtual void AddBoxOfficeReport(const std::shared_ptr<BoxOfficeReport> &) = 0;
            virtual void AddBoxOfficeReports(const std::vector<std::shared_ptr<BoxOfficeReport>> &) = 0;
            virtual unsigned long long int GetTotalBoxOfficeRevenue() const = 0;
            virtual void RemoveBoxOfficeReport(const std::shared_ptr<BoxOfficeReport> &) = 0;
        };
    }
}

#endif //TREKSTAR_PROJECTINTERFACE_H
