#ifndef TREKSTAR_PROJECTLISTVIEW_H
#define TREKSTAR_PROJECTLISTVIEW_H

#include "../ConsoleMessageView.h"
#include "../../model/project/Project.h"

using TrekStar::View::ConsoleMessageView;

namespace TrekStar
{
    namespace Project
    {
        class ProjectView : public ConsoleMessageView
        {
        public:
            ProjectView() = default;
            explicit ProjectView(ProjectInterface& model);

            void Present() override;

            ProjectInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
