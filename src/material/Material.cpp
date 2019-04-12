//
// Created by Matt Robinson on 2019-03-04.
//

#include "Material.h"
#include <vector>

namespace TrekStar {
    namespace Material {
        /**
          *  Trekstar Material Class Implementation
        */
        Material::Material(std::string line)
        {
//            std::vector<std::string> materialAttributes;
//
//            std::string::size_type pos = line.find('|');
//            line = line.substr(pos + 1);
//
//            while (pos != std::string::npos)
//            {
//                pos = line.find('|');
//                materialAttributes.push_back(line.substr(0, pos));
//                line = line.substr(pos + 1);
//            }
//
//            this->id = static_cast<unsigned int>(std::stoi(materialAttributes[0]));
//            this->title = materialAttributes[1];
//            this->format = materialAttributes[2];
//            this->audioFormat = materialAttributes[3];
//            this->runTime = materialAttributes[4];
//            this->language = materialAttributes[5];
//            this->retailPrice = std::stoul(materialAttributes[6], nullptr ,0);
//            this->subtitles = materialAttributes[7];
//            this->frameAspect = materialAttributes[8];
        }

        Material::Material(unsigned int id, const std::string & title)
        {
            this->id = id;
            this->title = title;
        }

        int Material::GetId() const
        {
            return id;
        }

        std::string Material::GetTitle() const
        {
            return title;
        }

        std::string Material::GetFormat() const
        {
            return format;
        }

        std::string Material::GetAudioFormat() const
        {
            return audioFormat;
        }

        int Material::GetRunTime() const
        {
            return runTime;
        }

        std::string Material::GetLanguage() const
        {
            return language;
        }

        double Material::GetRetailPrice() const
        {
            return retailPrice;
        }

        std::string Material::GetSubtitles() const
        {
            return subtitles;
        }

        std::string Material::GetFrameAspect() const
        {
            return frameAspect;
        }

        bool Material::operator==(const Material &material) const
        {
            return this->GetId() == material.GetId();
        }

        bool Material::operator!=(const Material &material) const
        {
            return this->GetId() != material.GetId();
        }
    }
}