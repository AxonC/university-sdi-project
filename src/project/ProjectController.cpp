#include "ProjectController.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectView ProjectController::Show(const Project & project)
        {
            return {project.ExportToSerialised()};
        }
    }
}
