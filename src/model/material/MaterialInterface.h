#ifndef TREKSTAR_MATERIALINTERFACE_H
#define TREKSTAR_MATERIALINTERFACE_H

#include <string>
#include <map>

#include "../Model.h"

using KeyValueMap = std::map<std::string, std::string>;

namespace TrekStar
{
    namespace Material
    {
        class MaterialInterface : public Model
        {
        public:
            virtual ~MaterialInterface() = default;
            virtual unsigned int GetId() const = 0;
            virtual std::string GetFormat() const = 0;
            virtual std::string GetAudioFormat() const = 0;
            virtual int GetRunTime() const = 0;
            virtual std::string GetLanguage() const = 0;
            virtual double GetRetailPrice() const = 0;
            virtual std::string GetSubtitles() const = 0;
            virtual std::string GetFrameAspect() const = 0;
            virtual KeyValueMap GetPresentableInformation() const = 0;
        };
    }
}

#endif //TREKSTAR_MATERIALINTERFACE_H
