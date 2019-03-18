//
// Created by Matt Robinson on 2019-03-18.
//

#include <vector>
#include <iostream>
#include "project/Project.h"

void listProjects(std::vector<TrekStar::Project::Project> projects)
{
    for (std::vector<TrekStar::Project::Project>::iterator it = projects.begin() ; it != projects.end(); ++it) {
        std::cout << std::string(80, '-') << std::endl;
        std::cout << "Title               : " << it->GetTitle() << std::endl;
        std::cout << "Summary             : " << it->GetSummary() << std::endl;
        std::cout << "Released            : " << it->GetReleased() << std::endl;
        std::cout << "Playing in theatres : " << it->GetPlayingInTheatres() << std::endl;
    }
}