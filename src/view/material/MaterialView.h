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
            explicit MaterialView(Material & model);

            void Present() override;

            Material* GetModel() override;
        };
    }
}

#endif //TREKSTAR_MATERIALVIEW_H
