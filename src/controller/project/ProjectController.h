#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "../../model/project/Project.h"
#include "../../view/project/ProjectView.h"
#include "../../model/project/ProjectInterface.h"
#include "../Controller.h"

namespace TrekStar
{
    namespace Project
    {
        class ProjectController : public Controller
        {
        private:
            ProjectInterface* model;
            ViewInterface* view;

        public:
            ProjectController() = default;
            ProjectController(ProjectInterface & model, ViewInterface & view);
            ~ProjectController() = default;

            void SetModel(ProjectInterface* & model);
            void SetView(ConsoleMessageView* & view);

            void ShowAll();
        };
    }
}



#endif //TREKSTAR_PROJECTCONTROLLER_H
