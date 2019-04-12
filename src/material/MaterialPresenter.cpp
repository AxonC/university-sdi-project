//
// Created by Matt Robinson on 2019-04-12.
//

#include <string>
#include "MaterialPresenter.h"
#include "DVD.h"
#include "BoxSet.h"

namespace TrekStar {
    namespace Material {
        std::map<std::string, std::string> MaterialPresenter::GetInformation(std::shared_ptr<Material> material)
        {
            std::map<std::string, std::string> materialData;
            std::string materialType = material->GetFormat();

            materialData =
            {
                {"ID", std::to_string(material->GetId())},
                {"Format", material->GetFormat()},
                {"Audio Format", material->GetAudioFormat()},
                {"Run Time", std::to_string(material->GetRunTime())},
                {"Language", material->GetLanguage()},
                {"Retail Price", std::to_string(material->GetRetailPrice())},
                {"Subtitles", material->GetSubtitles()},
                {"Frame Aspect", material->GetFrameAspect()}
            };

            // if material is a DVD
            if( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material) )
            {
                std::vector<std::string> additionalLanguageTracks = materialType->GetAdditionalLanguageTracks();
                int counter = 0;

                for(const auto &additionalLanguageTrack: additionalLanguageTracks)
                {
                    counter++;
                    materialData.insert ( std::pair<std::string, std::string>("Additional Language Track #" + std::to_string(counter), additionalLanguageTrack) );
                }


                std::vector<std::string> additionalSubtitleTracks = materialType->GetAdditionalSubtitleTracks();
                counter = 0;

                for(const auto &additionalSubtitleTrack: additionalSubtitleTracks)
                {
                    counter++;
                    materialData.insert ( std::pair<std::string, std::string>("Additional Subtitle Track #" + std::to_string(counter), additionalSubtitleTrack) );
                }


                std::vector<std::string> bonusFeatures = materialType->GetBonusFeatures();
                counter = 0;

                for(const auto &bonusFeature: bonusFeatures)
                {
                    counter++;
                    materialData.insert ( std::pair<std::string, std::string>("Bonus Feature #" + std::to_string(counter), bonusFeature) );
                }
            }
            else if ( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::BoxSet>(material) )
            {

            }
            else
            {

            }

            return materialData;
        }
    }
}