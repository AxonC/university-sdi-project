#include "CrewView.h"

namespace TrekStar
{
    namespace People
    {
        CrewView::CrewView(CrewInterface & model) : BaseView()
        {
            this->model = &model;
        }
    }
}