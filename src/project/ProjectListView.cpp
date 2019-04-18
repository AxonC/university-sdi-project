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

        void ProjectListView::Present() const
        {
            std::cout << this->GetModel()->;
        }

        Project* ProjectListView::GetModel() {
            return dynamic_cast<Project *>(this->model);
        }
    }
}


