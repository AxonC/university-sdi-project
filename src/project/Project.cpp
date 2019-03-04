//
// Created by Callum Axon on 2019-02-27
//

#include "Project.h"

namespace TrekStar {
    namespace Project {
        Project::Project(std::string & title)
        {
            this->title = title;
        }

        void Project::SetSummary(std::string & contents)
        {
            this->summary = contents;
        }

        std::string Project::GetSummary() const
        {
            return this->summary;
        }

        std::pair<std::string, std::string> Project::GetTitleSummary() const
        {
            return {this->title, this->GetSummary()};
        }

        Project::Project(std::string & name, std::string & summary)
        {
            this->title = name;
            this->summary = summary;
        }
    }
}

