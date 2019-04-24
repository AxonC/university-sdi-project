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
            std::string GetNewMaterialFormat();

            unsigned int GetUpdateOption();
            unsigned int GetMaterialSelection();

            ProjectInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
