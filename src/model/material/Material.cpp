#include "Material.h"
#include <vector>

namespace TrekStar
{
    namespace Material
    {
        /**
          *  Trekstar Material Class Implementation
        */
        unsigned int Material::GetId() const
        {
            return this->id;
        }

        std::string Material::GetFormat() const
        {
            return this->format;
        }

        std::string Material::GetAudioFormat() const
        {
            return this->audioFormat;
        }

        int Material::GetRunTime() const
        {
            return this->runTime;
        }

        std::string Material::GetLanguage() const
        {
            return this->language;
        }

        double Material::GetRetailPrice() const
        {
            return this->retailPrice;
        }

        std::string Material::GetSubtitles() const
        {
            return this->subtitles;
        }

        std::string Material::GetFrameAspect() const
        {
            return this->frameAspect;
        }

        std::string Material::GetPackaging() const
        {
            return this->packaging;
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
                    {"Frame Aspect", this->GetFrameAspect()},
                    {"Packaging", this->GetPackaging()}
                };
        }

        void Material::SetFormat(const std::string & format)
        {
            this->format = format;
        }

        void Material::SetAudioFormat(const std::string & audioFormat)
        {
            this->audioFormat = audioFormat;
        }

        void Material::SetRunTime(const int & runTime)
        {
            this->runTime = runTime;
        }

        void Material::SetLanguage(const std::string & language)
        {
            this->language = language;
        }

        void Material::SetRetailPrice(const double & retailPrice)
        {
            this->retailPrice = retailPrice;
        }

        void Material::SetSubtitles(const std::string & subtitles)
        {
            this->subtitles = subtitles;
        }

        void Material::SetFrameAspect(const std::string & frameAspect)
        {
            this->frameAspect = frameAspect;
        }

        void Material::SetPackaging(const std::string & packaging)
        {
            this->packaging = packaging;
        }

        std::shared_ptr<SerialisedMaterial> Material::ExportToSerialised() const
        {
            SerialisedMaterial serialisedMaterial =
                {
                    this->id,
                    this->format,
                    this->audioFormat,
                    this->runTime,
                    this->language,
                    this->retailPrice,
                    this->subtitles,
                    this->frameAspect,
                    this->packaging
                };

            return std::make_shared<SerialisedMaterial>(serialisedMaterial);
        }

        bool Material::operator==(const unsigned int & id) const
        {
            return this->GetId() == id;
        }

        bool Material::operator==(const Material &material) const
        {
            return this->GetId() == material.GetId();
        }

        bool Material::operator!=(const Material &material) const
        {
            return this->GetId() != material.GetId();
        }

        void to_json(json & j, const SerialisedMaterial & material)
        {
            j =
                {
                    {"id", material.id},
                    {"format", material.format},
                    {"audioFormat", material.audioFormat},
                    {"runTime", material.runTime},
                    {"language", material.language},
                    {"retailPrice", material.retailPrice},
                    {"subtitles", material.subtitles},
                    {"frameAspect", material.frameAspect},
                };
        }

        void from_json(const json & json, SerialisedMaterial & material)
        {
            json.at("id").get_to(material.id);
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