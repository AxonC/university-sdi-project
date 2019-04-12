//
// Created by Matt Robinson on 2019-03-18.
//

#include <vector>
#include <map>
#include <iostream>
#include "project/Project.h"
#include "material/MaterialPresenter.h"
#include "material/DVD.h"

using TrekStar::Project::Project;
using TrekStar::Material::Material;

void listProjects(std::vector<TrekStar::Project::Project> projects)
{
    int projectNum = 1;

    for(const auto &project: projects) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "Project " << projectNum << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::cout << "Title               : " << project.GetTitle() << std::endl;
        std::cout << "Summary             : " << project.GetSummary() << std::endl;
        std::cout << "Released            : " << project.GetReleased() << std::endl;
        std::cout << "Playing in theatres : " << project.GetPlayingInTheatres() << std::endl;
    }
}


void listMaterials(std::vector<TrekStar::Project::Project> projects, std::string projectNumString)
{
    int projectNum = std::stoi(projectNumString);
    std::vector<std::shared_ptr<TrekStar::Material::Material>> materials = projects[projectNum - 1].GetMaterials();

    for(const auto &material: materials)
    {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "Material " << material->GetId() << " for Project " << projectNum << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::map<std::string, std::string> materialData = TrekStar::Material::MaterialPresenter::GetInformation(material);

        std::cout << "Title : " << projects.at(projectNum - 1).GetTitle() << std::endl;

        for (auto const& m : materialData)
        {
            std::cout << m.first << " : " << m.second << std::endl;
        }

        // if material is a DVD
        if( auto materialType = std::dynamic_pointer_cast<TrekStar::Material::DVD>(material) )
        {
            std::vector<std::string> additionalLanguageTracks = materialType->GetAdditionalLanguageTracks();
            int counter = 0;

            for(const auto &additionalLanguageTrack: additionalLanguageTracks)
            {
                counter++;
                std::cout << "Additional Language Track #" << counter << " : " << additionalLanguageTrack << std::endl;
            }


            std::vector<std::string> additionalSubtitleTracks = materialType->GetAdditionalSubtitleTracks();
            counter = 0;

            for(const auto &additionalSubtitleTrack: additionalSubtitleTracks)
            {
                counter++;
                std::cout << "Additional Subtitle Track #" << counter << " : " << additionalSubtitleTrack << std::endl;
            }


            std::vector<std::string> bonusFeatures = materialType->GetBonusFeatures();
            counter = 0;

            for(const auto &bonusFeature: bonusFeatures)
            {
                counter++;
                std::cout << "Bonus Feature #" << counter << " : " << bonusFeature << std::endl;
            }
        }
    }
}