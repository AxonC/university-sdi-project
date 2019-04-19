//
// Created by Matt Robinson on 2019-04-16.
//

#ifndef SDI_PROJECT_VHSCONTROLLER_H
#define SDI_PROJECT_VHSCONTROLLER_H

#include <memory>

#include "../../model/material/Material.h"
#include "../../view/material/MaterialView.h"

namespace TrekStar
{
    namespace Material
    {
        class MaterialController
        {
        private:
            std::shared_ptr<Material> model;
            MaterialView view;

        public:
            MaterialController() = default;
            MaterialController(const std::shared_ptr<Material> & model, const MaterialView & view);
            ~MaterialController() = default;

            void SetModel(const std::shared_ptr<Material> & model);
            void SetView(const MaterialView & view);

            void ShowAll();
        };
    }
}

#endif //SDI_PROJECT_VHSCONTROLLER_H
