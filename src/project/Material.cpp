//
// Created by Matt Robinson on 2019-03-04.
//

#include "Material.h"

namespace TrekStar {
    namespace Material {

    /**
      *  Trekstar Material Class Implementation
    */
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

        std::string Material::getFormat()
        {
            return format;
        }

        std::string Material::getAudioFormat()
        {
            return audioFormat;
        }

        std::string Material::getRunTime()
        {
            return runTime;
        }

        std::string Material::getLanguage()
        {
            return language;
        }

        unsigned int Material::getRetailPrice()
        {
            return retailPrice;
        }

        std::string Material::getSubtitles()
        {
            return subtitles;
        }

        std::string Material::getFrameAspect()
        {
            return frameAspect;
        }

        bool Material::operator==(const Material &material) const
        {
            return this->GetId() == material.GetId();
        }

        bool Material::operator!=(const Material &material) const {
            return this->GetId() != material.GetId();
        }
    }
}