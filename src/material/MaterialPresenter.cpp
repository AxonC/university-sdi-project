//
// Created by Matt Robinson on 2019-04-12.
//

#include <string>
#include "MaterialPresenter.h"

namespace TrekStar {
    namespace Material {
        std::map<std::string, std::string> MaterialPresenter::GetInformation(std::shared_ptr<Material> material)
        {
            std::map<std::string, std::string> materialData;
            std::string materialType = material->GetFormat();

            if (materialType == "dvd")
            {
                materialData =
                {
                    {"ID", std::to_string(material->GetId())},
                    {"Format", material->GetFormat()},
                    {"Audio Format", material->GetAudioFormat()},
                    {"Run Time", std::to_string(material->GetRunTime())},
                    {"Language", material->GetLanguage()},
                    {"Retail Price", std::to_string(material->GetRetailPrice())},
                    {"Subtitles", material->GetSubtitles()},
                    {"Frame Aspect", material->GetFrameAspect()}
                };

                return materialData;
            }
            else if (materialType == "boxset")
            {

            }
            else
            {

            }
        }
    }
}