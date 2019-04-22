#ifndef TREKSTAR_PROJECTLISTVIEW_H
#define TREKSTAR_PROJECTLISTVIEW_H

#include "../BaseView.h"
#include "../../model/project/Project.h"

using TrekStar::View::BaseView;

namespace TrekStar
{
    namespace Project
    {
        class ProjectView : public BaseView
        {
        private:
            void DisplayVectorAsCSV(const std::vector<std::string> & stringVector);
        public:
            ProjectView() = default;
            explicit ProjectView(ProjectInterface & model);

            void Present() override;

            ProjectInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
