#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "../../model/project/Project.h"
#include "../../view/project/ProjectView.h"
#include "../../model/project/ProjectInterface.h"
#include "../BaseController.h"

namespace TrekStar
{
    namespace Project
    {
        class ProjectController : public BaseController
        {
        public:
            ProjectController() = default;
            ProjectController(ProjectInterface & model, ViewInterface & view);
            ~ProjectController() = default;

            void ShowAll() override;
            void ShowList() override;

            void UpdateProject();
            void AddNew();

            void ListMaterials();
            void AddMaterial();
            void UpdateMaterials();
            void RemoveMaterial();

            void ListCrew();
            void AddCrew();
            void UpdateCrew();
            void RemoveCrew();

            void ListBoxOfficeReports();

            bool ActorExists(std::string & searchCriteria);

        private:
            ProjectInterface* GetModel();
            ProjectView* GetView();
            void UpdateTitle();
            void UpdateSummary();
            void UpdateReleased();
            void UpdatePlayingInTheatres();
            void UpdateKeyword();
        };
    }
}

#endif //TREKSTAR_PROJECTCONTROLLER_H
