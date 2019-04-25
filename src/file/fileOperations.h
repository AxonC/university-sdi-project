#ifndef TREKSTAR_FILEOPERATIONS_H
#define TREKSTAR_FILEOPERATIONS_H

using json = nlohmann::json;

namespace TrekStar
{
    namespace Project
    {
        class Project;
        class BoxOfficeReport;
    } // namespace Project

    namespace Material
    {
        class Material;
    } // namespace Material

    namespace People
    {
        class Crew;
        struct SerializedCrew;
    }
} // namespace TrekStar

using ProjectVector = std::vector<TrekStar::Project::Project>;
using MaterialVector = std::vector<std::shared_ptr<TrekStar::Material::Material>>;
using CrewVector = std::vector<std::shared_ptr<TrekStar::People::Crew>>;
using BoxOfficeReportVector = std::vector<std::shared_ptr<TrekStar::Project::BoxOfficeReport>>;

namespace TrekStar
{
    namespace File
    {
        Project::Project createProject(const json &);

        MaterialVector createMaterials(const json &);

        BoxOfficeReportVector createBoxOfficeReports(const json &);

        ProjectVector importProjects(const std::string &);
    }
}

#endif //TREKSTAR_FILEOPERATIONS_H
