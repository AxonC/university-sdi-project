#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "../../model/project/Project.h"
#include "../../view/project/ProjectView.h"
#include "../Controller.h"

namespace TrekStar
{
    namespace Project
    {
//        struct ProjectView
//        {
//            SerialisedProject data;
//        };

        class ProjectController : public Controller
        {
        private:
            Project model;
            ProjectView view;

        public:
            ProjectController() = default;
            //ProjectController(Project & model, ProjectView & view);
            ProjectController(const Project & model, const ProjectView & view);
            ~ProjectController() = default;

            void SetModel(const Project & model);
            void SetView(const ProjectView & view);

            void ListProjects();
        };
    }
}



#endif //TREKSTAR_PROJECTCONTROLLER_H
