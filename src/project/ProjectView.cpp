#include <iostream>

#include "ProjectView.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectView::ProjectView(Project & model)
        : ConsoleMessageView()
        {
            this->model = &model;
        }

        void ProjectView::Present()
        {
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Project " << this->GetModel()->GetId() << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Title               : " << this->GetModel()->GetTitle() << std::endl;
            std::cout << "Summary             : " << this->GetModel()->GetSummary() << std::endl;
            std::cout << "Released            : " << this->GetModel()->GetReleased() << std::endl;
            std::cout << "Playing in theatres : " << this->GetModel()->GetPlayingInTheatres() << std::endl;
        }

        Project* ProjectView::GetModel()
        {
            return dynamic_cast<Project *>(this->model);
        }
    }
}


