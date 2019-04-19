#include <iostream>

#include "ProjectListView.h"

namespace TrekStar
{
    namespace Project
    {
        ProjectListView::ProjectListView(Project & model, TrekStar::Controller *controller)
        : ConsoleMessageView()
        {
            this->model = &model;
            this->SetController(controller);
        }

        void ProjectListView::Present()
        {
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Project " << this->GetModel()->GetId() << std::endl;
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Title               : " << this->GetModel()->GetTitle() << std::endl;
            std::cout << "Summary             : " << this->GetModel()->GetSummary() << std::endl;
            std::cout << "Released            : " << this->GetModel()->GetReleased() << std::endl;
            std::cout << "Playing in theatres : " << this->GetModel()->GetPlayingInTheatres() << std::endl;
        }

        Project* ProjectListView::GetModel()
        {
            return dynamic_cast<Project *>(this->model);
        }
    }
}


