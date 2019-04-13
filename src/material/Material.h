#ifndef TREKSTAR_MATERIAL_H
#define TREKSTAR_MATERIAL_H

#include <string>
#include "../lib/json.hpp"

using json = nlohmann::json;
using KeyValueMap = std::map<std::string, std::string>;

namespace TrekStar {
    namespace Material {
        struct SerialisedMaterial {
            std::string title;
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
        class Material
        {
            protected:
                unsigned int id;
                std::string title;
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
                explicit Material(unsigned int id, const std::string & title);
                virtual ~Material() = default;

                virtual KeyValueMap GetPresentableInformation() const;
                virtual void PopulateFromFile(const json &) = 0;

                int GetId() const;
                std::string GetTitle() const;
                std::string GetFormat() const;
                std::string GetAudioFormat() const;
                int GetRunTime() const;
                std::string GetLanguage() const;
                double GetRetailPrice() const;
                std::string GetSubtitles() const;
                std::string GetFrameAspect() const;

                SerialisedMaterial ExportToSerialised() const;

                bool operator==(const Material& material) const;
                bool operator!=(const Material& material) const;
        };

        json to_json(const SerialisedMaterial & material);
        void from_json(const json & json, SerialisedMaterial & material);
    }
}

#endif //TREKSTAR_MATERIAL_H
