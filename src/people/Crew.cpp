#include "Crew.h"

namespace TrekStar {
    namespace People {

        Crew::Crew(unsigned int id, const std::string & name)
        {
            this->id = id;
            this->name = name;
        }

        void Crew::SetJobTitle(const std::string & title)
        {
            this->jobTitle = title;
        }
    }
}