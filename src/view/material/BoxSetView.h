#ifndef TREKSTAR_BOXSETVIEW_H
#define TREKSTAR_BOXSETVIEW_H

#include "MaterialView.h"
#include "../../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Material
    {
        class BoxSetView : public MaterialView
        {
        public:
            explicit BoxSetView(BoxSet & model);

        private:
            BoxSet* GetModel() override;
        };
    }
}

#endif //TREKSTAR_BOXSETVIEW_H
