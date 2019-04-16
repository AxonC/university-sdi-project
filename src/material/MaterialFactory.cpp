#include "DVD.h"
#include "BoxSet.h"
#include "Bluray.h"

#include "MaterialFactory.h"
#include "DoubleSideDVD.h"

namespace TrekStar
{
    namespace Material
    {
        std::shared_ptr<Material> MaterialFactory::Create(const std::string & materialType)
        {
            if ( materialType == "dvd" )
            {
                return std::make_shared<DVD>();
            }
            else if ( materialType == "dsdvd" )
            {
                return std::make_shared<DoubleSideDVD>();
            }
            else if ( materialType == "boxset" )
            {
                return std::make_shared<BoxSet>();
            }
            else if ( materialType == "bluray")
            {
                return std::make_shared<Bluray>();
            }
            else
            {
                return nullptr;
            }
        }
    }
}

