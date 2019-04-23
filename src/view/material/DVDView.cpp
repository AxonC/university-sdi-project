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
                            {8, "Edit Content"},D
                            {9, "Cancel"}
                    },
                    "Update DVD"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        DVD* DVDView::GetModel()
        {
            return dynamic_cast<DVD*>(MaterialView::GetModel());
        }
    }
}