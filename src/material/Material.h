#ifndef TREKSTAR_MATERIAL_H
#define TREKSTAR_MATERIAL_H

#include <string>

namespace TrekStar {
    namespace Material {
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
                std::string runTime;
                std::string language;
                double retailPrice; // stored in pence
                std::string subtitles;
                std::string frameAspect;
            public:
                Material() = default;
                explicit Material(std::string materialLine);
                explicit Material(unsigned int id, const std::string & title);
                virtual ~Material() = default;

                virtual void PopulateFromFile(const std::vector<std::string> &) = 0;

                int GetId() const;
                std::string GetTitle() const;
                std::string GetFormat() const;
                std::string GetAudioFormat() const;
                std::string GetRunTime() const;
                std::string GetLanguage() const;
                double GetRetailPrice() const;
                std::string GetSubtitles() const;
                std::string GetFrameAspect() const;
                bool operator==(const Material& material) const;
                bool operator!=(const Material& material) const;
        };
    }
}

#endif //TREKSTAR_MATERIAL_H
