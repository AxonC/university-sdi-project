#include "MaterialController.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialController::MaterialController(MaterialInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }

        void MaterialController::ShowAll()
        {
            this->view->PresentAll();
        }

        void MaterialController::ShowList()
        {
            this->view->PresentList();
        }

        void MaterialController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();

            switch ( commandInput )
            {
                case 1:
                    this->UpdateAudioFormat();
                    break;
                case 2:
                    this->UpdateRunTime();
                    break;
                case 3:
                    this->UpdateLanguage();
                    break;
                case 4:
                    this->UpdateRetailPrice();
                    break;
                case 5:
                    this->UpdateSubtitles();
                    break;
                case 6:
                    this->UpdateFrameAspect();
                    break;
                case 7:
                    this->UpdatePackaging();
                    break;
                default:
                    break;
            }
        }

        MaterialInterface* MaterialController::GetModel()
        {
            return this->model;
        }

        MaterialView* MaterialController::GetView()
        {
            return dynamic_cast<MaterialView*>(this->view);
        }

        void MaterialController::UpdateAudioFormat()
        {
            this->model->SetAudioFormat(this->GetView()->GetNewAudioFormat());
        }

        void MaterialController::UpdateRunTime()
        {
            this->model->SetRunTime(this->GetView()->GetNewRunTime());
        }

        void MaterialController::UpdateLanguage()
        {
            this->model->SetLanguage(this->GetView()->GetNewLanguage());
        }

        void MaterialController::UpdateRetailPrice()
        {
            this->model->SetRetailPrice(this->GetView()->GetNewRetailPrice());
        }

        void MaterialController::UpdateSubtitles()
        {
            this->model->SetSubtitles(this->GetView()->GetNewSubtitles());
        }

        void MaterialController::UpdateFrameAspect()
        {
            this->model->SetFrameAspect(this->GetView()->GetNewFrameAspect());
        }

        void MaterialController::UpdatePackaging()
        {
            this->model->SetPackaging(this->GetView()->GetNewPackaging());
        }
    }
}