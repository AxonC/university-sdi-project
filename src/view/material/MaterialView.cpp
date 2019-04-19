#include <iostream>

#include "MaterialView.h"
#include "../../model/material/BoxSet.h"

namespace TrekStar
{
    namespace Material
    {
        MaterialView::MaterialView(Material & model) : ConsoleMessageView()
        {
            this->model = &model;
        }

        void MaterialView::Present()
        {
            std::cout << std::string(80, '-') << std::endl;
            std::cout << "Material " << this->GetModel()->GetId() << std::endl;
            std::cout << std::string(80, '-') << std::endl;

            std::map<std::string, std::string> materialData = this->GetModel()->GetPresentableInformation();

            for ( const auto & m : materialData )
            {
                std::cout << m.first << " : " << m.second << std::endl;
            }

//            if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(this->GetModel()) )
//            {
//                std::vector<std::map<std::string, std::string>> diskData = materialType->GetPresentableDiskInformation();
//
//                for ( const auto & d: diskData )
//                {
//                    for ( const auto & m: d )
//                    {
//                        std::cout << m.first << " : " << m.second << std::endl;
//                    }
//                }
//            }
        }

        Material* MaterialView::GetModel()
        {
            return dynamic_cast<Material *>(this->model);
        }
    }
}
