#include "BoxSet.h"
#include "../MaterialFactory/MaterialFactory.h"
#include "../DoubleSideDVD/DoubleSideDVD.h"

namespace TrekStar
{
    namespace Material
    {
        void BoxSet::PopulateFromFile(const json & j)
        {
            this->id = j.at("id").get<int>();
            this->format = j.at("format");
            this->retailPrice = j.at("retailPrice").get<double>();

            for ( const auto & dvd: j.at("dvds") )
            {
                std::shared_ptr<Material> currentDVD = TrekStar::Material::MaterialFactory::Create(dvd.at("format"));

                currentDVD->PopulateFromFile(dvd);

                this->disks.push(currentDVD);
            }
        }

        void BoxSet::AddDisks(const std::vector<std::shared_ptr<DVD>> & newDisks)
        {
            for ( const auto & disk: newDisks )
            {
                this->disks.push(disk);
            }
        }

        void BoxSet::AddDisk(const std::shared_ptr<DVD> & disk)
        {
            this->disks.push(disk);
        }

        Stack<std::shared_ptr<Material>> BoxSet::GetDisks() const
        {
            return this->disks;
        }

        KeyValueMap BoxSet::GetPresentableInformation() const
        {
            return
                {
                    {"Format", this->GetFormat()},
                    {"Retail Price", std::to_string(this->GetRetailPrice())}
                };
        }

        KeyValueMapVector BoxSet::GetPresentableDiskInformation() const
        {
            KeyValueMapVector information;

            for ( const auto & disk: this->disks.data() )
            {
                if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(disk) )
                {
                    auto info = materialType->GetPresentableDiskInformation();
                    information.insert(information.end(), info.begin(), info.end());
                }
                else if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(disk) )
                {
                    information.push_back(materialType->GetPresentableInformation());
                }
            }

            return information;
        }

        std::shared_ptr<SerialisedBoxSet> BoxSet::ExportToSerialised()
        {
            std::shared_ptr<SerialisedMaterial> serialisedMaterial = Material::ExportToSerialised();
            std::vector<std::shared_ptr<Material>> dvds;

            for ( const auto & dvd: this->disks.data() )
            {
                dvds.push_back(dvd);
            }

            SerialisedBoxSet boxSet(*serialisedMaterial, dvds);

            return std::make_shared<SerialisedBoxSet>(boxSet);
        }

        void to_json(json & j, const SerialisedBoxSet & serialisedBoxSet)
        {
            j["id"] = serialisedBoxSet.material.id;
            j["format"] = serialisedBoxSet.material.format;
            j["language"] = serialisedBoxSet.material.language;
            j["retailPrice"] = serialisedBoxSet.material.retailPrice;

            json dvdsJSON;
            for ( const auto & dvd: serialisedBoxSet.dvds )
            {
                json dvdJSON;

                dvdJSON["format"] = dvd->GetFormat();
                dvdJSON["audioFormat"] = dvd->GetAudioFormat();
                dvdJSON["runTime"] = dvd->GetRunTime();
                dvdJSON["language"] = dvd->GetLanguage();
                dvdJSON["retailPrice"] = dvd->GetRetailPrice();
                dvdJSON["subtitles"] = dvd->GetSubtitles();
                dvdJSON["frameAspect"] = dvd->GetFrameAspect();

                if ( auto castedDVD = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(dvd) )
                {
                    json dvdSides;

                    for ( const auto & side: castedDVD->GetSides() )
                    {
                        json dvdSide;

                        dvdSide["content"] = side.GetContent();
                        dvdSide["additionalLanguageTracks"] = side.GetAdditionalLanguageTracks();
                        dvdSide["additionalSubtitleTracks"] = side.GetAdditionalSubtitleTracks();
                        dvdSide["bonusFeatures"] = side.GetBonusFeatures();

                        dvdSides.push_back(dvdSide);
                    }

                    dvdJSON["sides"] = dvdSides;
                }
                else if ( auto castedDVD = std::dynamic_pointer_cast<TrekStar::Material::DVD>(dvd) )
                {
                    dvdJSON["content"] = castedDVD->GetSide().GetContent();
                    dvdJSON["additionalLanguageTracks"] = castedDVD->GetAdditionalLanguageTracks();
                    dvdJSON["additionalSubtitleTracks"] = castedDVD->GetAdditionalSubtitleTracks();
                    dvdJSON["bonusFeatures"] = castedDVD->GetBonusFeatures();
                }
                else
                {
                    // TO DO: handle incorrect DVD type
                }

                dvdsJSON.push_back(dvdJSON);
            }

            j["dvds"] = dvdsJSON;
        }
    }
}

