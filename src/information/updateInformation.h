#ifndef TREKSTAR_UPDATEINFORMATION_H
#define TREKSTAR_UPDATEINFORMATION_H

namespace TrekStar
{
    namespace Project
    {
        class Project;
        class ProjectView;
        class ProjectController;
    } // namespace Project
} // namespace TrekStar

namespace TrekStar
{
    namespace Information
    {
        void updateProject(std::vector<Project::Project> & projects, int projectID);
        void updateMaterials(std::vector<Project::Project> & projects, int projectID);
    }
}

#endif //TREKSTAR_UPDATEINFORMATION_H