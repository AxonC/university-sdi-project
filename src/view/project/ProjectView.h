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
            static void DisplayVectorAsCSV(const std::vector<std::string> & stringVector);
            static std::string GetStringInput();
            static bool GetBoolInput();
        public:
            ProjectView() = default;
            explicit ProjectView(ProjectInterface & model);

            void PresentAll() override;
            void PresentList() override;

            void PresentKeywords();
            void PresentMaterialsList();

            std::string GetNewTitle();
            std::string GetNewSummary();
            bool GetNewReleased();
            bool GetNewPlayingInTheatres();
            unsigned int GetKeywordNo();
            std::string GetNewKeyword(const unsigned int & keywordNo);

            unsigned int GetProjectUpdateOption();

            ProjectInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
