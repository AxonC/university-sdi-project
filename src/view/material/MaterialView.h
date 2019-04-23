#ifndef TREKSTAR_MATERIALVIEW_H
#define TREKSTAR_MATERIALVIEW_H

#include "../BaseView.h"
#include "../../model/material/Material.h"

using TrekStar::View::BaseView;

namespace TrekStar
{
    namespace Material
    {
        class MaterialView : public BaseView
        {
        public:
            MaterialView() = default;
            explicit MaterialView(MaterialInterface & model);

            void PresentAll() override;
            void PresentList() override;

            MaterialInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_MATERIALVIEW_H
