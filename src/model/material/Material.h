#ifndef TREKSTAR_MATERIAL_H
#define TREKSTAR_MATERIAL_H

#include <string>
#include "../Model.h"
#include "MaterialInterface.h"
#include "../../lib/json.hpp"

using json = nlohmann::json;
using KeyValueMap = std::map<std::string, std::string>;
using KeyValueMapVector = std::vector<KeyValueMap>;

namespace TrekStar
{
    namespace Material
    {
        struct SerialisedMaterial
        {
            unsigned int id;
            std::string format;
            std::string audioFormat;
            int runTime;
            std::string language;
            double retailPrice;
            std::string subtitles;
            std::string frameAspect;
            std::string packaging;
        };

        /**
         *  Trekstar Material Class
         */
        class Material : public MaterialInterface
        {
        protected:
            unsigned int id;
            std::string format;
            std::string audioFormat;
            int runTime = 0;
            std::string language;
            double retailPrice = 0; // stored in pence
            std::string subtitles;
            std::string frameAspect;
            std::string packaging;
        public:
            Material() = default;
            virtual ~Material() = default;

            virtual void PopulateFromFile(const json &) = 0;

            unsigned int GetId() const override;
            std::string GetFormat() const override;
            std::string GetAudioFormat() const override;
            int GetRunTime() const override;
            std::string GetLanguage() const override;
            double GetRetailPrice() const override;
            std::string GetSubtitles() const override;
            std::string GetFrameAspect() const override;
            std::string GetPackaging() const override;
            KeyValueMap GetPresentableInformation() const override;

            void SetAudioFormat(const std::string & audioFormat) override;
            void SetRunTime(const int & runTime) override;
            void SetLanguage(const std::string & language) override;
            void SetRetailPrice(const double & retailPrice) override;
            void SetSubtitles(const std::string & subtitles) override;
            void SetFrameAspect(const std::string & frameAspect) override;
            void SetPackaging(const std::string & packaging) override;

            std::shared_ptr<SerialisedMaterial> ExportToSerialised() const;

            bool operator==(const unsigned int & id) const override;
            bool operator==(const Material& material) const;
            bool operator!=(const Material& material) const;
        };

        void to_json(json & j, const SerialisedMaterial & material);
        void from_json(const json & json, SerialisedMaterial & material);
    }
}

#endif //TREKSTAR_MATERIAL_H
