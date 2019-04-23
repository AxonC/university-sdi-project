#include <iostream>

#include "ProjectView.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectView::ProjectView(ProjectInterface& model) : BaseView()
        {
            this->model = &model;
        }

        void ProjectView::PresentAll()
        {
            auto model = this->GetModel();

            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Project " << std::to_string(model->GetId()) << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Title               : " << model->GetTitle() << std::endl;
            std::cout << "Summary             : " << model->GetSummary() << std::endl;
            std::cout << "Released            : " << model->GetReleased() << std::endl;
            std::cout << "Playing in theatres : " << model->GetPlayingInTheatres() << std::endl;

            std::cout << "Keywords            : ";
            if ( model->GetKeywords().empty() )
            {
                std::cout << "No keywords...";
            }
            else
            {
                this->DisplayVectorAsCSV(model->GetKeywords());
            }
            std::cout << std::endl;

            std::cout << "Available on        : ";
            if ( model->GetMaterialFormats().empty() )
            {
                std::cout << "No material formats...";
            }
            else
            {
                this->DisplayVectorAsCSV(model->GetMaterialFormats());
            }
            std::cout << std::endl;
        }

        void ProjectView::PresentList()
        {
            auto model = this->GetModel();

            std::cout << "ID: " << std::to_string(model->GetId()) << ", ";
            std::cout << "Title: " << model->GetTitle() << std::endl;
        }

        void ProjectView::PresentKeywords()
        {
            unsigned int counter = 0;
            for ( const auto & keyword: this->GetModel()->GetKeywords() )
            {
                counter++;
                std::cout << "Keyword #" << counter << ": " << keyword << std::endl;
            }
        }

        std::string ProjectView::GetNewTitle()
        {
            std::cout << "Title [current: " << this->GetModel()->GetTitle() << "]: ";
            return this->GetStringInput();
        }

        std::string ProjectView::GetNewSummary()
        {
            std::cout << "Summary [current: " << this->GetModel()->GetSummary() << "]: ";
            return this->GetStringInput();
        }

        bool ProjectView::GetNewReleased()
        {
            std::cout << "Released [current: " << this->GetModel()->GetReleased() << "]: ";
            return this->GetBoolInput();
        }

        bool ProjectView::GetNewPlayingInTheatres()
        {
            std::cout << "Released [current: " << this->GetModel()->GetPlayingInTheatres() << "]: ";
            return this->GetBoolInput();
        }

        unsigned int ProjectView::GetKeywordNo()
        {
            unsigned int keywordNo = 0;

            while ( keywordNo < 1 || keywordNo > this->GetModel()->GetKeywords().size() )
            {
                std::cout << "Keyword # [1 - " << this->GetModel()->GetKeywords().size() << "]: ";
                std::cin >> keywordNo;
            }

            return keywordNo - 1;
        }

        std::string ProjectView::GetNewKeyword(const unsigned int & keywordNo)
        {
            std::cout << "Keyword #" << keywordNo << " [current: " << this->GetModel()->GetKeywords().at(keywordNo) << "]: ";
            return this->GetStringInput();
        }

        ProjectInterface* ProjectView::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }

        void ProjectView::DisplayVectorAsCSV(const std::vector<std::string> & stringVector)
        {
            if ( !stringVector.empty() )
            {
                std::copy(std::begin(stringVector), std::prev(std::end(stringVector)), std::ostream_iterator<std::string>(std::cout, ", "));
                std::cout << stringVector.back();
            }
        }

        std::string ProjectView::GetStringInput()
        {
            std::string input;

            std::cin.ignore();
            std::getline(std::cin, input);

            return input;
        }

        bool ProjectView::GetBoolInput()
        {
            std::string input;

            while ( input != "y" && input != "n" )
            {
                std::cin.ignore();
                std::getline(std::cin, input);
            }

            return input == "y";
        }
    }
}


