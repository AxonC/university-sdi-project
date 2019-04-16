#include "VHSController.h"

namespace TrekStar
{
    namespace Material
    {
        VHSView ProjectController::Show(const VHS & vhs)
        {
            return {vhs.ExportToSerialised()};
        }
    }
}