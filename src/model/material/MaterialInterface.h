#ifndef TREKSTAR_MATERIALINTERFACE_H
#define TREKSTAR_MATERIALINTERFACE_H

#include "../Model.h"

using KeyValueMap = std::map<std::string, std::string>;

namespace TrekStar
{
    namespace Material
    {
     class MaterialInterface : public TrekStar::Model
     {
        public:
            ~MaterialInterface() override = default;
            virtual unsigned int GetId() const = 0;
            virtual std::string GetFormat() const = 0;
            virtual std::string GetAudioFormat() const = 0;
            virtual int GetRunTime() const = 0;
            virtual std::string GetLanguage() const = 0;
            virtual double GetRetailPrice() const = 0;
            virtual std::string GetSubtitles() const = 0;
            virtual std::string GetFrameAspect() const = 0;
            virtual std::string GetPackaging() const = 0;
            virtual KeyValueMap GetPresentableInformation() const = 0;

            virtual void SetFormat(const std::string & format) = 0;
            virtual void SetAudioFormat(const std::string & audioFormat) = 0;
            virtual void SetRunTime(const int & runTime) = 0;
            virtual void SetLanguage(const std::string & language) = 0;
            virtual void SetRetailPrice(const double & retailPrice) = 0;
            virtual void SetSubtitles(const std::string & subtitles) = 0;
            virtual void SetFrameAspect(const std::string & frameAspect) = 0;
            virtual void SetPackaging(const std::string & packaging) = 0;

            virtual bool operator==(const unsigned int & id) const = 0;
        };
    }
}

#endif //TREKSTAR_MATERIALINTERFACE_H
