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
        private:
            BoxSetView* GetView() override;
            BoxSet* GetModel() override;

        public:
            BoxSetController(BoxSet & model, BoxSetView & view);

            void Update() override;
            void AddNew() override;
        };
    }
}

#endif //TREKSTAR_BOXSETCONTROLLER_H
