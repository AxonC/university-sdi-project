#include <iostream>
#include "BoxSet.h"
#include "MaterialFactory.h"
#include "DoubleSideDVD.h"

namespace TrekStar {
    namespace Material {
        BoxSet::BoxSet(unsigned int id, std::string name) : Material(id, name) {}

        void BoxSet::AddDisks(const std::vector<std::shared_ptr<DVD>> & newDisks)
        {
            for (const auto & disk: newDisks) {
                this->disks.push(disk);
            }
        }

        void BoxSet::PopulateFromFile(const json & j)
        {
            this->id = j.at("id").get<int>();
            this->format = j.at("format");
            this->retailPrice = j.at("retailPrice").get<double>();

            for(const auto & dvd: j.at("dvds"))
            {
                std::shared_ptr<Material> currentDVD = TrekStar::Material::MaterialFactory::Create(dvd.at("format"));

                std::cout << dvd << std::endl;
                currentDVD->PopulateFromFile(dvd);

                this->disks.push(currentDVD);
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

            for(const auto & disk: this->disks.data())
            {
                if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(disk) ) {
                    auto info = materialType->GetPresentableDiskInformation();
                    information.insert(information.end(), info.begin(), info.end());
                } else if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(disk) ) {
                    information.push_back(materialType->GetPresentableInformation());
                }
            }

            return information;
        }

        SerialisedBoxSet BoxSet::ExportToSerialised()
        {
            SerialisedBoxSet boxSet;

            boxSet.dvds = this->GetDisks().data();

            return boxSet;
        }

//        void TrekStar::Material::to_json(const SerialisedBoxSet &dvd, const std::shared_ptr<Material> &materialObject)
//        {
////            json j = TrekStar::Material::to_json(materialObject->ExportToSerialised());
//
//            json dvds;
//            for(auto & singleDvd: dvd.dvds)
//            {
//                json i;
//
//                if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DoubleSideDVD>(singleDvd) )
//                {
//                    i = TrekStar::Material::to_json(materialType->ExportToSerialised(), singleDvd);
//                }
//            }
//
//            j["dvds"] = dvds;
//        }
    }
}

