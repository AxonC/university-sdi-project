#ifndef PROJECT_PROJECT_H
#define PROJECT_PROJECT_H

#include <string>
#include <utility>

#include "ProjectInterface.h"

namespace TrekStar {
    namespace Project {
        /**
         *  Trekstar Film Project Class
         */
        class Project : public ProjectInterface
        {
            public:
                Project() {};
                explicit Project(std::string & title);
                explicit Project(std::string & name, std::string & summary);
                ~Project();

                std::string GetSummary() const override;
                void SetSummary(std::string & contents);

                std::pair<std::string, std::string> GetTitleSummary() const;

            private:
                std::string title;
                std::string summary;
        };
    }
}

#endif //PROJECT_PROJECT_H
