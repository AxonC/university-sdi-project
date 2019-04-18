#ifndef TREKSTAR_PROJECTLISTVIEW_H
#define TREKSTAR_PROJECTLISTVIEW_H

#include "../view/ConsoleMessageView.h"
#include "Project.h"

using TrekStar::View::ConsoleMessageView;

namespace TrekStar
{
    namespace Project
    {
        class ProjectListView : public ConsoleMessageView
        {
        public:
            ProjectListView(Project & model, Controller* controller);

            void Present() const override;

            Project* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
