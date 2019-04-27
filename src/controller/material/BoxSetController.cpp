#include "BoxSetController.h"

namespace TrekStar
{
    namespace Material
    {
        BoxSetController::BoxSetController(BoxSet & model, BoxSetView & view) : MaterialController(model, view) {}

        void BoxSetController::Update()
        {

        }

        void BoxSetController::AddNew()
        {

        }

        BoxSetView* BoxSetController::GetView()
        {
            return dynamic_cast<BoxSetView*>(MaterialController::GetView());
        }

        BoxSet* BoxSetController::GetModel()
        {
            return dynamic_cast<BoxSet*>(MaterialController::GetModel());
        }
    }
}
