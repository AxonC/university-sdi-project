#include "Bluray.h"

namespace TrekStar
{
    namespace Material
    {
        Bluray::Bluray() : DVD() {}

        std::shared_ptr<SerialisedBluray> Bluray::ExportToSerialised() const
        {
            std::shared_ptr<SerialisedMaterial> serialisedMaterial = Material::ExportToSerialised();

            SerialisedBluray doubleSideDVD(*serialisedMaterial, this->sideOne.ExportToSerialised());

            return std::make_shared<SerialisedBluray>(doubleSideDVD);
        }

        void to_json(json & j, const SerialisedBluray & dvd)
        {
            j["id"] = dvd.material.id;
            j["format"] = dvd.material.format;
            j["audioFormat"] = dvd.material.audioFormat;
            j["runTime"] = dvd.material.runTime;
            j["language"] = dvd.material.language;
            j["retailPrice"] = dvd.material.retailPrice;
            j["subtitles"] = dvd.material.subtitles;
            j["frameAspect"] = dvd.material.frameAspect;

            j["content"] = dvd.sideOne.content;
            j["additionalLanguageTracks"] = dvd.sideOne.additionalLanguageTracks;
            j["additionalSubtitleTracks"] = dvd.sideOne.additionalSubtitleTracks;
            j["bonusFeatures"] = dvd.sideOne.bonusFeatures;
        }
    }
}