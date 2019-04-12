//
// Created by Matt Robinson on 2019-04-12.
//

#ifndef TREKSTAR_MATERIALPRESENTER_H
#define TREKSTAR_MATERIALPRESENTER_H

#include <map>
#include "Material.h"

namespace TrekStar {
    namespace Material {
        class MaterialPresenter {
        public:
            MaterialPresenter() = default;
            ~MaterialPresenter() = default;

            static std::map<std::string, std::string> GetInformation(std::shared_ptr<Material>);
        };
    }
}

#endif //TREKSTAR_MATERIALPRESENTER_H
