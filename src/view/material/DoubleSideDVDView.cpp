#include <iostream>

#include "DoubleSideDVDView.h"
#include "DVDView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace Material
    {
        DoubleSideDVDView::DoubleSideDVDView(DoubleSideDVD & model) : MaterialView(model) {}

        unsigned int DoubleSideDVDView::GetUpdateOption()
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
                            {8, "Edit Side One Content"},
                            {9, "Edit Side One Additional Language Tracks"},
                            {10, "Edit Side One Additional Subtitle Tracks"},
                            {11, "Edit Side One Bonus Features"},
                            {12, "Edit Side Two Content"},
                            {13, "Edit Side Two Additional Language Tracks"},
                            {14, "Edit Side Two Additional Subtitle Tracks"},
                            {15, "Edit Side Two Bonus Features"},
                            {16, "Cancel"}
                    },
                    "Update DVD"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int DoubleSideDVDView::GetSideOneAdditionalLanguageTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetAdditionalLanguageTracks().size(), "Additional Language Track");
        }

        unsigned int DoubleSideDVDView::GetSideOneAdditionalSubtitleTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetAdditionalSubtitleTracks().size(), "Additional Subtitle Track");
        }

        unsigned int DoubleSideDVDView::GetSideOneBonusFeatureNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetBonusFeatures().size(), "Bonus Feature");
        }

        unsigned int DoubleSideDVDView::GetSideTwoAdditionalLanguageTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetAdditionalLanguageTracks().size(), "Additional Language Track");
        }

        unsigned int DoubleSideDVDView::GetSideTwoAdditionalSubtitleTrackNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetAdditionalSubtitleTracks().size(), "Additional Subtitle Track");
        }

        unsigned int DoubleSideDVDView::GetSideTwoBonusFeatureNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetSideOne().GetBonusFeatures().size(), "Bonus Feature");
        }

        void DoubleSideDVDView::PresentSideOneAdditionalLanguageTracks()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideOne().GetAdditionalLanguageTracks() )
            {
                counter++;
                std::cout << "Language Track #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DoubleSideDVDView::PresentSideOneAdditionalSubtitleTracks()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideOne().GetAdditionalSubtitleTracks() )
            {
                counter++;
                std::cout << "Subtitle Track #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DoubleSideDVDView::PresentSideOneBonusFeatures()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideOne().GetBonusFeatures() )
            {
                counter++;
                std::cout << "Bonus Feature #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DoubleSideDVDView::PresentSideTwoAdditionalLanguageTracks()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideTwo().GetAdditionalLanguageTracks() )
            {
                counter++;
                std::cout << "Language Track #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DoubleSideDVDView::PresentSideTwoAdditionalSubtitleTracks()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideTwo().GetAdditionalSubtitleTracks() )
            {
                counter++;
                std::cout << "Subtitle Track #" << counter << ": " << languageTrack << std::endl;
            }
        }

        void DoubleSideDVDView::PresentSideTwoBonusFeatures()
        {
            unsigned int counter = 0;
            for ( const auto & languageTrack: this->GetModel()->GetSideTwo().GetBonusFeatures() )
            {
                counter++;
                std::cout << "Bonus Feature #" << counter << ": " << languageTrack << std::endl;
            }
        }

        std::string DoubleSideDVDView::GetNewSideOneContent()
        {
            std::string currentContent = this->GetModel()->GetSideOne().GetContent();

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

        std::string DoubleSideDVDView::GetNewSideOneAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo)
        {
            std::cout << "Additional Language Track #" << additionalLanguageTrackNo + 1 << " [current: " << this->GetModel()->GetSideOne().GetAdditionalLanguageTracks().at(additionalLanguageTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DoubleSideDVDView::GetNewSideOneAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo)
        {
            std::cout << "Additional Subtitle Track #" << additionalSubtitleTrackNo + 1 << " [current: " << this->GetModel()->GetSideOne().GetAdditionalSubtitleTracks().at(additionalSubtitleTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DoubleSideDVDView::GetNewSideOneBonusFeature(const unsigned int & bonusFeatureNo)
        {
            std::cout << "Bonus Feature #" << bonusFeatureNo + 1 << " [current: " << this->GetModel()->GetSideOne().GetBonusFeatures().at(bonusFeatureNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DoubleSideDVDView::GetNewSideTwoContent()
        {
            std::string currentContent = this->GetModel()->GetSideTwo().GetContent();

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

        std::string DoubleSideDVDView::GetNewSideTwoAdditionalLanguageTrack(const unsigned int & additionalLanguageTrackNo)
        {
            std::cout << "Additional Language Track #" << additionalLanguageTrackNo + 1 << " [current: " << this->GetModel()->GetSideTwo().GetAdditionalLanguageTracks().at(additionalLanguageTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DoubleSideDVDView::GetNewSideTwoAdditionalSubtitleTrack(const unsigned int & additionalSubtitleTrackNo)
        {
            std::cout << "Additional Subtitle Track #" << additionalSubtitleTrackNo + 1 << " [current: " << this->GetModel()->GetSideTwo().GetAdditionalSubtitleTracks().at(additionalSubtitleTrackNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        std::string DoubleSideDVDView::GetNewSideTwoBonusFeature(const unsigned int & bonusFeatureNo)
        {
            std::cout << "Bonus Feature #" << bonusFeatureNo + 1 << " [current: " << this->GetModel()->GetSideTwo().GetBonusFeatures().at(bonusFeatureNo) << "]: ";
            return TrekStar::Command::GetStringInput();
        }

        DoubleSideDVD* DoubleSideDVDView::GetModel()
        {
            return dynamic_cast<DoubleSideDVD*>(MaterialView::GetModel());
        }
    }
}
