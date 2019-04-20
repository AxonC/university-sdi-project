#include <iostream>

#include "ProjectView.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectView::ProjectView(ProjectInterface& model) : ConsoleMessageView()
        {
            this->model = &model;
        }

        void ProjectView::Present()
        {
            auto model = this->GetModel();

            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Project " << std::to_string(model->GetId()) << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Title               : " << model->GetTitle() << std::endl;
            std::cout << "Summary             : " << model->GetSummary() << std::endl;
            std::cout << "Released            : " << model->GetReleased() << std::endl;
            std::cout << "Playing in theatres : " << model->GetPlayingInTheatres() << std::endl;
        }

        ProjectInterface* ProjectView::GetModel()
        {
            return dynamic_cast<ProjectInterface*>(this->model);
        }
    }
}


