#include <iostream>

#include "DVDView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace Material
    {
        DVDView::DVDView(DVD & model) : MaterialView(model) {}

        std::string DVDView::GetNewContent()
        {
            std::string currentContent = this->GetModel()->GetContent();

            if ( currentContent.empty() )
            {
                std::cout << "Content: ";
            }
            else
            {
                std::cout << "Content [current: " << currentContent << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        unsigned int DVDView::GetUpdateOption()
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
                            {8, "Edit Content"},
                            {9, "Edit Additional Language Tracks"},
                            {10, "Edit Additional Subtitle Tracks"},
                            {11, "Edit Bonus Features"},
                            {12, "Cancel"}
                    },
                    "Update DVD"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int DVDView::GetAdditionalLanguageTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetAdditionalLanguageTracks().size(), "Additional Language Track");
        }

        unsigned int DVDView::GetAdditionalSubtitleTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetAdditionalLanguageTracks().size(), "Additional Subtitle Track");
        }

        unsigned int DVDView::GetBonusFeatureNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetAdditionalLanguageTracks().size(), "Bonus Feature");
        }

        void DVDView::PresentAdditionalLanguageTracks()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetAdditionalLanguageTracks() )
            {
                counter++;
                std::cout << "Language Track #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DVDView::PresentAdditionalSubtitleTracks()
        {
            unsigned int counter = 0;
            for ( const auto & subtitleTrack: this->GetModel()->GetAdditionalSubtitleTracks() )
            {
                counter++;
                std::cout << "Subtitle Track #" << counter << ": " << subtitleTrack << std::endl;
            }
        }

        void DVDView::PresentBonusFeatures()
        {
            unsigned int counter = 0;
            for ( const auto & bonusFeature: this->GetModel()->GetBonusFeatures() )
            {
                counter++;
                std::cout << "Bonus Feature #" << counter << ": " << bonusFeature << std::endl;
            }
        }

        std::string DVDView::GetNewAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo)
        {
            std::cout << "Additional Language Track #" << additionalLanguageTrackNo << " [current: " << this->GetModel()->GetAdditionalLanguageTracks().at(additionalLanguageTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DVDView::GetNewAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo)
        {
            std::cout << "Additional Subtitle Track #" << additionalSubtitleTrackNo << " [current: " << this->GetModel()->GetAdditionalSubtitleTracks().at(additionalSubtitleTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DVDView::GetNewBonusFeature(const unsigned int & bonusFeatureNo)
        {
            std::cout << "Bonus Feature #" << bonusFeatureNo << " [current: " << this->GetModel()->GetAdditionalSubtitleTracks().at(bonusFeatureNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        DVD* DVDView::GetModel()
        {
            return dynamic_cast<DVD*>(MaterialView::GetModel());
        }
    }
}