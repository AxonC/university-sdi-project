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
