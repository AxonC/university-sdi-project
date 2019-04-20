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
            int runTime;
            std::string language;
            double retailPrice; // stored in pence
            std::string subtitles;
            std::string frameAspect;
        public:
            Material() = default;
            explicit Material(std::string materialLine);
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
            KeyValueMap GetPresentableInformation() const override;

            std::shared_ptr<SerialisedMaterial> ExportToSerialised() const;

            bool operator==(const Material& material) const;
            bool operator!=(const Material& material) const;
        };

        void to_json(json & j, const SerialisedMaterial & material);
        void from_json(const json & json, SerialisedMaterial & material);
    }
}

#endif //TREKSTAR_MATERIAL_H
