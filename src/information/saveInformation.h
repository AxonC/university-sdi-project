#ifndef SDI_PROJECT_SAVEINFORMATION_H
#define SDI_PROJECT_SAVEINFORMATION_H

// forward declarations
namespace TrekStar
{
    namespace Project
    {
        class Project;
    } // namespace Project

    namespace People
    {
        class Crew;
        struct SerializedCrew;
    }
} // namespace TrekStar

namespace TrekStar
{
    namespace Information
    {
        void save(std::vector<Project::Project> & projects, const std::string & filePath);
    }
}

#endif //SDI_PROJECT_SAVEINFORMATION_H
