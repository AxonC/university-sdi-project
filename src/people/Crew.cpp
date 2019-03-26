#include "Crew.h"

namespace TrekStar {
    namespace People {

        Crew::Crew(unsigned int id, const std::string & name)
        {
            this->id = id;
            this->name = name;
        }
    }
}