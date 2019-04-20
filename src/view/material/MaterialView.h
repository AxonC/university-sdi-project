#ifndef TREKSTAR_MATERIALVIEW_H
#define TREKSTAR_MATERIALVIEW_H

#include "../ConsoleMessageView.h"
#include "../../model/material/Material.h"

using TrekStar::View::ConsoleMessageView;

namespace TrekStar
{
    namespace Material
    {
        class MaterialView : public ConsoleMessageView
        {
        public:
            MaterialView() = default;
            explicit MaterialView(MaterialInterface & model);

            void Present() override;

            MaterialInterface* GetModel() override;
        };
    }
}

#endif //TREKSTAR_MATERIALVIEW_H
