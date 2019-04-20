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
        };
    }
}



#endif //TREKSTAR_PROJECTCONTROLLER_H
