#include "MaterialController.h"

namespace TrekStar
{
    namespace Material
    {
        /**
            Class:                 MaterialController
            Method Name:           MaterialController (constructor)
            Method Access Control: Public

            Constructs the Material controller based on the base class constructor.

            @param MaterialInterface object
            @param ViewInterface object
        */
        MaterialController::MaterialController(MaterialInterface & model, ViewInterface & view) : BaseController()
        {
            this->model = &model;
            this->view = &view;
        }


        /**
            Class:                 MaterialController
            Method Name:           ShowAll
            Method Access Control: Public

            Responsible for ordering the view to display all information for the Material.
        */
        void MaterialController::ShowAll()
        {
            this->view->PresentAll();
        }


        /**
            Class:                 MaterialController
            Method Name:           ShowList
            Method Access Control: Public

            Responsible for ordering the view to display a summary list of information for the Material.
        */
        void MaterialController::ShowList()
        {
            this->view->PresentList();
        }


        /**
            Class:                 MaterialController
            Method Name:           Update
            Method Access Control: Public

            Responsible for determining which attributes of the Material are to be updated.
        */
        void MaterialController::Update()
        {
            unsigned int commandInput = this->GetView()->GetUpdateOption();  // Get user selection for the attribute
                                                                             // they wish to update.

            // Call the relevant private member function of DoubleSideDVDController based on user selection.
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
                default:
                    break;
            }
        }


        /**
           Class:                 MaterialController
           Method Name:           AddNew
           Method Access Control: Public

           Responsible for allowing the user to create a new Material.
        */
        void MaterialController::AddNew()
        {
            this->UpdateAudioFormat();
            this->UpdateRunTime();
            this->UpdateLanguage();
            this->UpdateRetailPrice();
            this->UpdateSubtitles();
            this->UpdateFrameAspect();
        }


        /**
          Class:                 MaterialController
          Method Name:           SetFormat
          Method Access Control: Public

          Responsible for allowing the format of the Material to be set.
        */
        void MaterialController::SetFormat(const std::string & format)
        {
            this->model->SetFormat(format);
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateAudioFormat
          Method Access Control: Public

          Responsible for allowing the audio format of the Material to be updated.
        */
        void MaterialController::UpdateAudioFormat()
        {
            this->model->SetAudioFormat(this->GetView()->GetNewAudioFormat());
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateRunTime
          Method Access Control: Public

          Responsible for allowing the run time of the Material to be updated.
        */
        void MaterialController::UpdateRunTime()
        {
            this->model->SetRunTime(this->GetView()->GetNewRunTime());
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateLanguage
          Method Access Control: Public

          Responsible for allowing the language of the Material to be updated.
        */
        void MaterialController::UpdateLanguage()
        {
            this->model->SetLanguage(this->GetView()->GetNewLanguage());
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateLanguage
          Method Access Control: Public

          Responsible for allowing the retail price of the Material to be updated.
        */
        void MaterialController::UpdateRetailPrice()
        {
            this->model->SetRetailPrice(this->GetView()->GetNewRetailPrice());
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateSubtitles
          Method Access Control: Public

          Responsible for allowing the subtitles of the Material to be updated.
        */
        void MaterialController::UpdateSubtitles()
        {
            this->model->SetSubtitles(this->GetView()->GetNewSubtitles());
        }


        /**
          Class:                 MaterialController
          Method Name:           UpdateFrameAspect
          Method Access Control: Public

          Responsible for allowing the frame aspect of the Material to be updated.
        */
        void MaterialController::UpdateFrameAspect()
        {
            this->model->SetFrameAspect(this->GetView()->GetNewFrameAspect());
        }


        /**
           Class:                 MaterialController
           Method Name:           GetView
           Method Access Control: Protected

           Responsible for allowing access to the Materials view object.

           @return A pointer to the MaterialView object.
        */
        MaterialView* MaterialController::GetView()
        {
            return dynamic_cast<MaterialView*>(this->view);
        }


        /**
           Class:                 MaterialController
           Method Name:           GetModel
           Method Access Control: Private

           Responsible for accessing the Material interface.

           @return A pointer to the MaterialInterface object.
        */
        MaterialInterface* MaterialController::GetModel()
        {
            return this->model;
        }
    }
}