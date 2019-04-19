#ifndef TREKSTAR_PROJECTLISTVIEW_H
#define TREKSTAR_PROJECTLISTVIEW_H

#include "../view/ConsoleMessageView.h"
#include "Project.h"

using TrekStar::View::ConsoleMessageView;

namespace TrekStar
{
    namespace Project
    {
        class ProjectView : public ConsoleMessageView
        {
        public:
            ProjectView() = default;
            ProjectView(Project & model);

            void Present() override;

            Project* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
