#ifndef TREKSTAR_MATERIALFACTORY_H
#define TREKSTAR_MATERIALFACTORY_H

#include <memory>

#include "Material.h"

using TrekStar::Material::Material;

namespace TrekStar
{
    namespace Material
    {
        class MaterialFactory
        {
        public:
            MaterialFactory() = default;
            ~MaterialFactory() = default;

            static std::shared_ptr<Material> Create(const std::string & materialType);
        };
    }
}

#endif //TREKSTAR_MATERIALFACTORY_H
