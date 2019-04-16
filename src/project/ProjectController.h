#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "Project.h"

namespace TrekStar
{
    namespace Project
    {
        struct ProjectView
        {
            SerialisedProject data;
        };

        class ProjectController
        {
        private:
            Project model;
        public:
            ProjectController() = default;
            ~ProjectController() = default;

            static ProjectView Show(const Project & project);
        };
    }
}



#endif //TREKSTAR_PROJECTCONTROLLER_H
