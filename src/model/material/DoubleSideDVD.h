#ifndef TREKSTAR_DOUBLESIDEDVD_H
#define TREKSTAR_DOUBLESIDEDVD_H

#include "DoubleSideDVDInterface.h"
#include "DVD.h"
namespace TrekStar
{
    namespace Material
    {
        struct SerialisedDoubleSideDVD
        {
            explicit SerialisedDoubleSideDVD(const SerialisedMaterial & baseMaterial, const std::vector<SerialisedDVDSide> & sides)
            {
                this->sides = sides;
                this->material = baseMaterial;
            }
            SerialisedMaterial material;
            std::vector<SerialisedDVDSide> sides;
        };

        class DoubleSideDVD: public DVD, public DoubleSideDVDInterface
        {
        protected:
            DVDSide sideTwo;

        public:
            DoubleSideDVD() = default;

            void PopulateFromFile(const json &) override;

            std::vector<DVDSide> GetSides() const;
            DVDSide GetSideOne() const override;
            DVDSide GetSideTwo() const override;
            KeyValueMapVector GetPresentableDiskInformation() const;

            void SetSideOneAdditionalLanguageTracks(const std::vector<std::string> & additionalLanguageTracks);
            void SetSideOneAdditionalSubtitleTracks(const std::vector<std::string> & additionalSubtitleTracks);
            void SetSideOneBonusFeatures(const std::vector<std::string> & bonusFeatures);
            void SetSideTwoAdditionalLanguageTracks(const std::vector<std::string> & additionalLanguageTracks);
            void SetSideTwoAdditionalSubtitleTracks(const std::vector<std::string> & additionalSubtitleTracks);
            void SetSideTwoBonusFeatures(const std::vector<std::string> & bonusFeatures);

            void SetSideOneContent(const std::string & content);
            void SetSideOneAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack);
            void SetSideOneAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack);
            void SetSideOneBonusFeature(unsigned int index, const std::string & bonusFeature);
            void SetSideTwoContent(const std::string & content);
            void SetSideTwoAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack);
            void SetSideTwoAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack);
            void SetSideTwoBonusFeature(unsigned int index, const std::string & bonusFeature);

            std::shared_ptr<SerialisedDoubleSideDVD> ExportToSerialised() const;
        };

        void to_json(json & j, const SerialisedDoubleSideDVD & serialisedDoubleSideDVD);
    }
}


#endif //TREKSTAR_DOUBLESIDEDVD_H
