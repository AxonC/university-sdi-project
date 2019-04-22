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
    }
}


