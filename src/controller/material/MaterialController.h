#ifndef SDI_PROJECT_MATERIALCONTROLLER_H
#define SDI_PROJECT_MATERIALCONTROLLER_H

#include <memory>

#include "../../model/material/Material.h"
#include "../../view/material/MaterialView.h"
#include "../../model/material/MaterialInterface.h"
#include "../Controller.h"

namespace TrekStar
{
    namespace Material
    {
        class MaterialController : public Controller
        {
        private:
            MaterialInterface* model;
            ViewInterface* view;

        public:
            MaterialController() = default;
            MaterialController(MaterialInterface & model, ViewInterface & view);
            ~MaterialController() = default;

            void SetModel(MaterialInterface* & model);
            void SetView(ConsoleMessageView* & view);

            void ShowAll();
        };
    }
}

#endif //SDI_PROJECT_MATERIALCONTROLLER_H
