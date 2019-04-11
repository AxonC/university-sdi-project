#include "DVD.h"
#include "BoxSet.h"

#include "MaterialFactory.h"

namespace TrekStar {
    namespace Material {
        std::shared_ptr<Material> MaterialFactory::Create(const std::string & materialType)
        {
            if (materialType == "dvd") {
                return std::make_shared<DVD>();
            } else if (materialType == "boxset") {
                return std::make_shared<BoxSet>();
            }else {
                return nullptr;
            }
        }
    }
}

