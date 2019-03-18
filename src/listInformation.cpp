//
// Created by Matt Robinson on 2019-03-18.
//

#include <vector>
#include <iostream>
#include "project/Project.h"

void listProjects(std::vector<TrekStar::Project::Project> projects)
{
    int projectNum = 1;
    for (std::vector<TrekStar::Project::Project>::iterator it = projects.begin() ; it != projects.end(); ++it) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "Project " << projectNum << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::cout << "Title               : " << it->GetTitle() << std::endl;
        std::cout << "Summary             : " << it->GetSummary() << std::endl;
        std::cout << "Released            : " << it->GetReleased() << std::endl;
        std::cout << "Playing in theatres : " << it->GetPlayingInTheatres() << std::endl;

        projectNum++;
    }
}


void listMaterials(std::vector<TrekStar::Project::Project> projects, std::string projectNumString)
{
    int projectNum = std::stoi(projectNumString);
    std::vector<TrekStar::Material::Material> materials = projects[projectNum - 1].GetMaterials();

    int materialNum = 1;
    for (std::vector<TrekStar::Material::Material>::iterator it = materials.begin() ; it != materials.end(); ++it) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "Material " << it->GetId() << " for Project " << projectNum << std::endl;
        std::cout << std::string(80, '-') << std::endl;

        std::cout << "Title        : " << it->GetTitle() << std::endl;
        std::cout << "Format       : " << it->GetFormat() << std::endl;
        std::cout << "Audio format : " << it->GetAudioFormat() << std::endl;
        std::cout << "Run time     : " << it->GetRunTime() << std::endl;
        std::cout << "Language     : " << it->GetLanguage() << std::endl;
        std::cout << "Retail price : " << it->GetRetailPrice() << std::endl;
        std::cout << "Subtitles    : " << it->GetSubtitles() << std::endl;
        std::cout << "Frame aspect : " << it->GetFrameAspect() << std::endl;

        materialNum++;
    }
}