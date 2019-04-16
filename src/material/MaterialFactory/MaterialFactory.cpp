#include "MaterialFactory.h"

#include "../DVD/DVD.h"
#include "../DoubleSideDVD/DoubleSideDVD.h"
#include "../BoxSet/BoxSet.h"
#include "../Bluray/Bluray.h"
#include "../VHS/VHS.h"

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
            else if ( materialType == "bluray" )
            {
                return std::make_shared<Bluray>();
            }
            else if ( materialType == "vhs" )
            {
                return std::make_shared<VHS>();
            }
            else
            {
                return nullptr;
            }
        }
    }
}

