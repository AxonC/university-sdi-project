#include <iostream>

#include "MaterialView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"
#include "../../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialView::MaterialView(MaterialInterface & model) : BaseView()
        {
            this->model = &model;
        }

        void MaterialView::PresentAll()
        {
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Material " << this->GetModel()->GetId() << std::endl;
            std::cout << std::string(80, '-') << std::endl;

            std::map<std::string, std::string> materialData = this->GetModel()->GetPresentableInformation();

            for ( const auto & m : materialData )
            {
                std::cout << m.first << " : " << m.second << std::endl;
            }

            if ( auto materialType = dynamic_cast<TrekStar::Material::BoxSet *>(this->model) )
            {
                std::vector<std::map<std::string, std::string>> diskData = materialType->GetPresentableDiskInformation();

                for ( const auto & d: diskData )
                {
                    for ( const auto & m: d )
                    {
                        std::cout << m.first << " : " << m.second << std::endl;
                    }
                }
            }
        }

        void MaterialView::PresentList()
        {
            auto model = this->GetModel();

            std::cout << "ID: " << std::to_string(model->GetId()) << ", ";
            std::cout << "Format: " << model->GetFormat() << std::endl;
        }

        std::string MaterialView::GetNewFormat()
        {
            std::string currentFormat = this->GetModel()->GetFormat();

            if ( currentFormat.empty() )
            {
                std::cout << "Format: ";
            }
            else
            {
                std::cout << "Title [current: " << currentFormat << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        std::string MaterialView::GetNewAudioFormat()
        {
            std::string currentAudioFormat = this->GetModel()->GetAudioFormat();

            if ( currentAudioFormat.empty() )
            {
                std::cout << "Audio Format: ";
            }
            else
            {
                std::cout << "Audio Format [current: " << currentAudioFormat << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        int MaterialView::GetNewRunTime()
        {
            int currentRunTime = this->GetModel()->GetRunTime();

            if ( currentRunTime == 0 )
            {
                std::cout << "Run Time: ";
            }
            else
            {
                std::cout << "Run Time [current: " << currentRunTime << "]: ";
            }

            return TrekStar::Command::GetIntInput();
        }

        std::string MaterialView::GetNewLanguage()
        {
            std::string currentLanguage = this->GetModel()->GetLanguage();

            if ( currentLanguage.empty() )
            {
                std::cout << "Language: ";
            }
            else
            {
                std::cout << "Language [current: " << currentLanguage << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        double MaterialView::GetNewRetailPrice()
        {
            int currentRetailPrice = this->GetModel()->GetRunTime();

            if ( currentRetailPrice == 0 )
            {
                std::cout << "Retail Price: ";
            }
            else
            {
                std::cout << "Retail Price [current: " << currentRetailPrice << "]: ";
            }

            return TrekStar::Command::GetIntInput();
        }

        std::string MaterialView::GetNewSubtitles()
        {
            std::string currentSubtitles = this->GetModel()->GetSubtitles();

            if ( currentSubtitles.empty() )
            {
                std::cout << "Subtitles: ";
            }
            else
            {
                std::cout << "Subtitles [current: " << currentSubtitles << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        std::string MaterialView::GetNewFrameAspect()
        {
            std::string currentFrameAspect = this->GetModel()->GetSubtitles();

            if ( currentFrameAspect.empty() )
            {
                std::cout << "Frame Aspect: ";
            }
            else
            {
                std::cout << "Frame Aspect [current: " << currentFrameAspect << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        std::string MaterialView::GetNewPackaging()
        {
            std::string currentPackaging = this->GetModel()->GetPackaging();

            if ( currentPackaging.empty() )
            {
                std::cout << "Subtitles: ";
            }
            else
            {
                std::cout << "Subtitles [current: " << currentPackaging << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        unsigned int MaterialView::GetUpdateOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Edit Audio Format"},
                            {2, "Edit Run Time"},
                            {3, "Edit Language"},
                            {4, "Edit Retail Price"},
                            {5, "Edit Subtitles"},
                            {6, "Edit Frame Aspect"},
                            {7, "Edit Packaging"},
                            {8, "Cancel"}
                    },
                    "Update Material"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        MaterialInterface* MaterialView::GetModel()
        {
            return dynamic_cast<MaterialInterface*>(this->model);
        }
    }
}
