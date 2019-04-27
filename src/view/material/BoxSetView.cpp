#include "BoxSetView.h"
#include "../../command/CommandHandler.h"
#include "../../command/userInput.h"

namespace TrekStar
{
    namespace Material
    {
        BoxSetView::BoxSetView(BoxSet & model) : MaterialView(model) {}

        unsigned int BoxSetView::GetUpdateOption()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "Edit Audio Format"},
                            {2, "Edit Run Time"},
                            {3, "Edit Language"},
                            {4, "Edit Retail Price"},
                            {5, "Edit Subtitles"},
                            {6, "Edit Frame Aspect"},
                            {7, "Add Disk"},
                            {8, "Edit Disks"},
                            {9, "Remove Disk"},
                            {10, "Cancel"}
                    },
                    "Update BoxSet"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        unsigned int BoxSetView::GetDiskNo()
        {
            return TrekStar::Command::GetIndexInput(this->GetModel()->GetDisks().size(), "Disk");
        }

        unsigned int BoxSetView::GetNoOfDisks()
        {
            std::cout << "Number of Disks for BoxSet: ";
            return TrekStar::Command::GetIntInput();
        }

        unsigned int BoxSetView::GetNewDiskType()
        {
            TrekStar::Command::CommandHandler commandHandler = TrekStar::Command::CommandHandler (
                    {
                            {1, "DVD"},
                            {2, "Double Sided DVD"},
                            {3, "Bluray"}
                    },
                    "New Disk Type"
            );

            commandHandler.displayCommands();
            int commandInput = commandHandler.getUserInput();
            commandHandler.clearConsole();

            return commandInput;
        }

        void BoxSetView::PresentDisks()
        {
            unsigned int counter = 0;
            for ( const auto & disk: this->GetModel()->GetDisks().data() )
            {
                counter++;
                std::cout << "Disk #" << counter << ": ";
                std::cout << "Format: " << std::dynamic_pointer_cast<TrekStar::Material::Material>(disk)->GetFormat() << std::endl;
            }
        }

        void BoxSetView::PresentLastDisk()
        {
            std::cout << "Going to remove disk with format ";
            std::cout << std::dynamic_pointer_cast<TrekStar::Material::Material>(this->GetModel()->GetDisks().peak())->GetFormat() << "." << std::endl;
        }

        bool BoxSetView::GetRemoveConfirmation()
        {
            std::cout << "Remove this disk? (y/n): ";
            return TrekStar::Command::GetBoolInput();
        }

        BoxSet* BoxSetView::GetModel()
        {
            return dynamic_cast<BoxSet*>(MaterialView::GetModel());
        }
    }
}
