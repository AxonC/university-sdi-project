#ifndef TREKSTAR_BOXSETCONTROLLER_H
#define TREKSTAR_BOXSETCONTROLLER_H

#include "MaterialController.h"
#include "../../view/material/BoxSetView.h"
#include "../../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Material
    {
        class BoxSetController : public MaterialController
        {
        public:
            BoxSetController(BoxSet & model, BoxSetView & view);

            void Update() override;
            void AddNew() override;

        private:
            void AddDisks();
            void AddDisk();
            void UpdateDisks();
            void RemoveDisk();

            std::shared_ptr<DVD> GetNewDisk();

            BoxSetView* GetView() override;
            BoxSet* GetModel() override;
        };
    }
}

#endif //TREKSTAR_BOXSETCONTROLLER_H
