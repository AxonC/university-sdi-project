#include "DoubleSideDVD.h"
#include <iostream>

namespace TrekStar {
    namespace Material {
        DoubleSideDVD::DoubleSideDVD(unsigned int id, const std::string &name) : DVD(id, name)
        {

        }

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

            for (const auto & side: sides)
            {
                if (sides.size() > 2) {
                    break; // no more than two sides allowed.
                }

                std::string content = side.at("content");
                StringVector languageTracks;
                StringVector subtitleTracks;
                StringVector bonusFeatures;

                for (auto &it : side.at("additionalLanguageTracks")) {
                    languageTracks.push_back(it);
                }

                for (auto & it: side.at("additionalSubtitleTracks")) {
                    subtitleTracks.push_back(it);
                }

                for (auto & it: side.at("bonusFeatures")) {
                    bonusFeatures.push_back(it);
                }

                dvdSides.emplace_back(content, languageTracks, subtitleTracks, bonusFeatures);
            }

            this->sideOne = dvdSides.at(0);
            this->sideTwo = dvdSides.at(1);
        }

        KeyValueMap DoubleSideDVD::GetPresentableInformation() const
        {
            KeyValueMap information = Material::GetPresentableInformation();

            KeyValueMap sideOne = this->sideOne.GetPresentableInformation();
            information.insert(sideOne.begin(), sideOne.end());

            KeyValueMap sideTwo = this->sideTwo.GetPresentableInformation();
            information.insert(sideTwo.begin(), sideTwo.end());

            return information;
        }
    }
}

