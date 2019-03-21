#include "DVD.h"
#include "MaterialFactory.h"

namespace TrekStar {
    namespace Material {
        std::shared_ptr<Material> MaterialFactory::Create(const std::string & materialType)
        {
            if (materialType == "dvd") {
                return std::make_shared<DVD>();
            } else {
                return nullptr;
            }
        }
    }
}

