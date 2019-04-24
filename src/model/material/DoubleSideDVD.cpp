#include "pch.h"
#include "DoubleSideDVD.h"

namespace TrekStar
{
    namespace Material
    {
        void DoubleSideDVD::PopulateFromFile(const json & j)
        {
            this->format = j.at("format");
            this->audioFormat = j.at("audioFormat");
            this->runTime = j.at("runTime").get<int>();
            this->language = j.at("language");
            this->retailPrice = j.at("retailPrice").get<double>();
            this->frameAspect = j.at("frameAspect");

            json sides = j.at("sides");

            std::vector<DVDSide> dvdSides;

            for ( const auto & side: sides )
            {
                if ( sides.size() > 2 )
                {
                    break; // no more than two sides allowed.
                }

                std::string content = side.at("content");
                StringVector languageTracks;
                StringVector subtitleTracks;
                StringVector bonusFeatures;

                for ( auto & it : side.at("additionalLanguageTracks") )
                {
                    languageTracks.push_back(it);
                }

                for ( auto & it: side.at("additionalSubtitleTracks") )
                {
                    subtitleTracks.push_back(it);
                }

                for ( auto & it: side.at("bonusFeatures") )
                {
                    bonusFeatures.push_back(it);
                }

                dvdSides.emplace_back(content, languageTracks, subtitleTracks, bonusFeatures);
            }

            this->sideOne = dvdSides.at(0);
            this->sideTwo = dvdSides.at(1);
        }

        std::vector<DVDSide> DoubleSideDVD::GetSides() const
        {
            return {this->sideOne, this->sideTwo};
        }

        DVDSide DoubleSideDVD::GetSideOne() const
        {
            return this->sideOne;
        }

        DVDSide DoubleSideDVD::GetSideTwo() const
        {
            return this->sideTwo;
        }

        KeyValueMapVector DoubleSideDVD::GetPresentableDiskInformation() const
        {
            KeyValueMapVector information;

            information.push_back(Material::GetPresentableInformation());

            KeyValueMap sideOne = this->sideOne.GetPresentableInformation();
            information.push_back(sideOne);

            KeyValueMap sideTwo = this->sideTwo.GetPresentableInformation();
            information.push_back(sideTwo);

            return information;
        }

        void DoubleSideDVD::SetSideOneContent(const std::string & content)
        {
            this->sideOne.SetContent(content);
        }

        void DoubleSideDVD::SetSideOneAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack)
        {
            this->sideOne.SetAdditionalLanguageTrack(index, languageTrack);
        }

        void DoubleSideDVD::SetSideOneAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack)
        {
            this->sideOne.SetAdditionalSubtitleTrack(index, subtitleTrack);
        }

        void DoubleSideDVD::SetSideOneBonusFeature(unsigned int index, const std::string & bonusFeature)
        {
            this->sideOne.SetBonusFeature(index, bonusFeature);
        }

        void DoubleSideDVD::SetSideTwoContent(const std::string & content)
        {
            this->sideTwo.SetContent(content);
        }

        void DoubleSideDVD::SetSideTwoAdditionalLanguageTrack(unsigned int index, const std::string & languageTrack)
        {
            this->sideTwo.SetAdditionalLanguageTrack(index, languageTrack);
        }

        void DoubleSideDVD::SetSideTwoAdditionalSubtitleTrack(unsigned int index, const std::string & subtitleTrack)
        {
            this->sideTwo.SetAdditionalSubtitleTrack(index, subtitleTrack);
        }

        void DoubleSideDVD::SetSideTwoBonusFeature(unsigned int index, const std::string & bonusFeature)
        {
            this->sideTwo.SetBonusFeature(index, bonusFeature);
        }

        std::shared_ptr<SerialisedDoubleSideDVD> DoubleSideDVD::ExportToSerialised() const
        {
            std::shared_ptr<SerialisedMaterial> serialisedMaterial = Material::ExportToSerialised();
            std::vector<SerialisedDVDSide> serialisedDVDSides;

            serialisedDVDSides.push_back(this->sideOne.ExportToSerialised());
            serialisedDVDSides.push_back(this->sideTwo.ExportToSerialised());

            SerialisedDoubleSideDVD doubleSideDVD(*serialisedMaterial, serialisedDVDSides);

            return std::make_shared<SerialisedDoubleSideDVD>(doubleSideDVD);
        }

        void to_json(json & j, const SerialisedDoubleSideDVD & serialisedDoubleSideDVD)
        {
            j["id"] = serialisedDoubleSideDVD.material.id;
            j["format"] = serialisedDoubleSideDVD.material.format;
            j["audioFormat"] = serialisedDoubleSideDVD.material.audioFormat;
            j["runTime"] = serialisedDoubleSideDVD.material.runTime;
            j["language"] = serialisedDoubleSideDVD.material.language;
            j["retailPrice"] = serialisedDoubleSideDVD.material.retailPrice;
            j["subtitles"] = serialisedDoubleSideDVD.material.subtitles;
            j["frameAspect"] = serialisedDoubleSideDVD.material.frameAspect;

            json sidesJSON;
            for ( const auto & side: serialisedDoubleSideDVD.sides )
            {
                json sideJSON;

                sideJSON["content"] = side.content;
                sideJSON["additionalLanguageTracks"] = side.additionalLanguageTracks;
                sideJSON["additionalSubtitleTracks"] = side.additionalSubtitleTracks;
                sideJSON["bonusFeatures"] = side.bonusFeatures;

                sidesJSON.push_back(sideJSON);
            }

            j["sides"] = sidesJSON;
        }
    }
}

