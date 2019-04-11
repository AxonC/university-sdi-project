//
// Created by Matt Robinson on 2019-03-18.
//

#include <vector>
#include <iostream>
#include "project/Project.h"
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

        std::cout << "Title        : " << material->GetTitle() << std::endl;
        std::cout << "Format       : " << material->GetFormat() << std::endl;
        std::cout << "Audio format : " << material->GetAudioFormat() << std::endl;
        std::cout << "Run time     : " << material->GetRunTime() << std::endl;
        std::cout << "Language     : " << material->GetLanguage() << std::endl;
        std::cout << "Retail price : " << material->GetRetailPrice() << std::endl;
        std::cout << "Subtitles    : " << material->GetSubtitles() << std::endl;
        std::cout << "Frame aspect : " << material->GetFrameAspect() << std::endl;

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
        }
    }
}