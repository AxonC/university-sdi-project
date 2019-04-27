#include "BoxSetView.h"

namespace TrekStar
{
    namespace Material
    {
        BoxSetView::BoxSetView(BoxSet & model) : MaterialView(model) {}

        BoxSet* BoxSetView::GetModel()
        {
            return dynamic_cast<BoxSet*>(MaterialView::GetModel());
        }
    }
}
