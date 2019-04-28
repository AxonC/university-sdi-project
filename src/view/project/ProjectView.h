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
            void PresentCrewList();
            void PresentBoxOfficeReportsList();

            std::string GetNewTitle();
            std::string GetNewSummary();
            bool GetNewReleased();
            bool GetNewPlayingInTheatres();
            unsigned int GetKeywordNo();
            std::string GetNewKeyword(const unsigned int & keywordNo);
            std::string GetNewMaterialFormat();

            unsigned int GetNoOfKeywords();

            unsigned int GetUpdateOption();
            unsigned int GetMaterialSelection();
            unsigned int GetCrewSelection();
            unsigned int GetBoxOfficeReportSelection();

            unsigned int GetListMaterialsOption();
            unsigned int GetCurrentMaterial(unsigned int currentMaterial, unsigned int commandInput);
            unsigned int GetListCrewOption();
            unsigned int GetCurrentCrew(unsigned int currentCrew, unsigned int commandInput);
            unsigned int GetListBoxOfficeReportsOption();
            unsigned int GetCurrentBoxOfficeReport(unsigned int currentBoxOfficeReport, unsigned int commandInput);

            void DisplayCannotAddMaterial();
            void DisplayHasNoMaterials();
            void DisplayHasNoCrew();
            void DisplayHasNoBoxOfficeReports();
            void DisplayCannotAddBoxOfficeReport();

            ProjectInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_PROJECTLISTVIEW_H
