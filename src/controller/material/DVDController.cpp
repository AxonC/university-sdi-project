#include "DVDController.h"

#include <iostream>

namespace TrekStar
{
    namespace Material
    {
        DVDController::DVDController(DVD & model, DVDView & view) : MaterialController(model, view) {}

        void DVDController::UpdateContent()
        {
            this->GetModel()->SetContent(this->GetView()->GetNewContent());
        }

        void DVDController::Update()
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
            case 8:
                this->UpdateContent();
                break;
            default:
                break;
            }
        }

        DVDView* DVDController::GetView()
        {
            return dynamic_cast<DVDView*>(MaterialController::GetView());
        }

        DVD* DVDController::GetModel()
        {
            return dynamic_cast<DVD*>(MaterialController::GetModel());
        }
    }
}