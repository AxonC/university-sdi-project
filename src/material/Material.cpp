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

        std::shared_ptr<SerialisedMaterial> Material::ExportToSerialised() const
        {
            SerialisedMaterial serialisedMaterial =
            {
                this->title,
                this->format,
                this->audioFormat,
                this->runTime,
                this->language,
                this->retailPrice,
                this->subtitles,
                this->frameAspect
            };

            return std::make_shared<SerialisedMaterial>(serialisedMaterial);
        }

        bool Material::operator==(const Material &material) const
        {
            return this->GetId() == material.GetId();
        }

        bool Material::operator!=(const Material &material) const
        {
            return this->GetId() != material.GetId();
        }

        KeyValueMap Material::GetPresentableInformation() const
        {
            return
                {
                    {"Format", this->GetFormat()},
                    {"Audio Format", this->GetAudioFormat()},
                    {"Run Time", std::to_string(this->GetRunTime())},
                    {"Language", this->GetLanguage()},
                    {"Retail Price", std::to_string(this->GetRetailPrice())},
                    {"Subtitles", this->GetSubtitles()},
                    {"Frame Aspect", this->GetFrameAspect()}
                };
        }

        void to_json(json & j, const SerialisedMaterial & material)
        {
            j =
            {
                {"format", material.format},
                {"audioFormat", material.audioFormat},
                {"runTime", material.runTime},
                {"language", material.language},
                {"retailPrice", material.retailPrice},
                {"subtitles", material.subtitles},
                {"frameAspect", material.frameAspect}
            };
        }

        void from_json(const json & json, SerialisedMaterial & material)
        {
            json.at("format").get_to(material.format);
            json.at("audioFormat").get_to(material.audioFormat);
            json.at("runTime").get_to(material.runTime);
            json.at("language").get_to(material.language);
            json.at("retailPrice").get_to(material.retailPrice);
            json.at("subtitles").get_to(material.subtitles);
            json.at("frameAspect").get_to(material.frameAspect);
        }
    }
}