#include <iostream>

#include "VHSView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace Material
    {
        VHSView::VHSView(VHS & model) : MaterialView(model) {}

        unsigned int VHSView::GetUpdateOption()
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
                            {8, "Edit Audio Track"},
                            {9, "Cancel"}
                    },
                    "Update VHS"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        std::string VHSView::GetNewAudioTrack()
        {
            std::string currentAudioTrack = this->GetModel()->GetAudioTrack();

            if ( currentAudioTrack.empty() )
            {
                std::cout << "Content: ";
            }
            else
            {
                std::cout << "Content [current: " << currentAudioTrack << "]: ";
            }

            return TrekStar::Command::GetStringInput();
        }

        VHS* VHSView::GetModel()
        {
            return dynamic_cast<VHS*>(MaterialView::GetModel());
        }
    }
}
