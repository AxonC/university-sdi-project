#ifndef TREKSTAR_PROJECTCONTROLLER_H
#define TREKSTAR_PROJECTCONTROLLER_H

#include "Project.h"

namespace TrekStar {
    namespace Project {
        class ProjectController {
         public:
            ProjectController() = default;
            ~ProjectController() = default;

            Project FindOrFail(unsigned int id);
            void Persist(const Project &);
        };
    }
}



#endif //TREKSTAR_PROJECTCONTROLLER_H
