#include "VHS.h"

namespace TrekStar {
    namespace Material {
        VHS::VHS() : Material() {}

        void VHS::PopulateFromFile(const json & j)
        {
            this->format = j.at("format");
            this->audioFormat = j.at("audioFormat");
            this->runTime = j.at("runTime").get<int>();
            this->language = j.at("language");
            this->retailPrice = j.at("retailPrice").get<double>();
            this->subtitles = j.at("subtitles");
            this->frameAspect = j.at("frameAspect");
            this->audioTrack = j.at("audioTrack");
        }

        std::string VHS::GetAudioTrack()
        {
            return this->audioTrack;
        }

        void VHS::SetAudioTrack(const std::string & audioTrack)
        {
            this->audioTrack = audioTrack;
        }

        KeyValueMap VHS::GetPresentableInformation() const
        {
            // call the base class function to get the basic details.
            KeyValueMap information = Material::GetPresentableInformation();

            information.emplace("Audio Track", this->audioTrack);

            return information;
        }

        void to_json(json & j, const SerialisedVHS & serialisedVHS)
        {
            j["id"] = serialisedVHS.material.id;
            j["format"] = serialisedVHS.material.format;
            j["audioFormat"] = serialisedVHS.material.audioFormat;
            j["audioTrack"] = serialisedVHS.audioTrack; // specific to a VHS material
            j["runTime"] = serialisedVHS.material.runTime;
            j["language"] = serialisedVHS.material.language;
            j["retailPrice"] = serialisedVHS.material.retailPrice;
            j["subtitles"] = serialisedVHS.material.subtitles;
            j["frameAspect"] = serialisedVHS.material.frameAspect;
        }
    }
}

