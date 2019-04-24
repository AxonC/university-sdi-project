#ifndef TREKSTAR_DVD_H
#define TREKSTAR_DVD_H

#include "Material.h"
#include "DVDInterface.h"
#include "DVDSide.h"

using TrekStar::Material::Material;

namespace TrekStar
{
    namespace Material
    {
        struct SerialisedDVD
        {
            explicit SerialisedDVD(const SerialisedMaterial & baseMaterial, const SerialisedDVDSide & dvdSide)
            {
                this->sideOne = dvdSide;
                this->material = baseMaterial;
            }
            SerialisedMaterial material;
            SerialisedDVDSide sideOne;
        };

        /**
         *  Trekstar DVD Class
         */
        class DVD : public Material, public DVDInterface
        {
        protected:
            DVDSide sideOne;
        public:
            DVD();

            void PopulateFromFile(const json &) override;

            std::string GetContent() const override;
            std::vector<std::string> GetAdditionalLanguageTracks() const;
            std::vector<std::string> GetAdditionalSubtitleTracks() const;
            std::vector<std::string> GetBonusFeatures() const;
            DVDSide GetSide() const;

            KeyValueMap GetPresentableInformation() const override;

            void SetAdditionalLanguageTracks(const std::vector<std::string> & additionalLanguageTracks) override;
            void SetAdditionalSubtitleTracks(const std::vector<std::string> & additionalSubtitleTracks) override;
            void SetBonusFeatures(const std::vector<std::string> & bonusFeatures) override;

            void SetContent(const std::string & content) override;
            void SetAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack) override;
            void SetAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack) override;
            void SetBonusFeature(unsigned int index, const std::string & bonusFeature) override;

            std::shared_ptr<SerialisedDVD> ExportToSerialised() const;
        };

        void to_json(json & j, const SerialisedDVD & dvd);
        void from_json(const json & j, SerialisedDVD & dvd);
    }
}

#endif //TREKSTAR_DVD_H
