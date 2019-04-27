#include "pch.h"

#include "BoxOfficeReportController.h"

namespace TrekStar
{
    namespace Project
    {
        BoxOfficeReportController::BoxOfficeReportController(BoxOfficeReportInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void BoxOfficeReportController::ShowAll()
        {
            this->view->PresentAll();
        }

        void BoxOfficeReportController::ShowList()
        {
            this->view->PresentList();
        }

        BoxOfficeReportInterface* BoxOfficeReportController::GetModel()
        {
            return dynamic_cast<BoxOfficeReportInterface*>(this->model);
        }

        BoxOfficeReportView* BoxOfficeReportController::GetView()
        {
            return dynamic_cast<BoxOfficeReportView*>(this->view);
        }
    }
}
