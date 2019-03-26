#ifndef TREKSTAR_CREW_H
#define TREKSTAR_CREW_H

#include <string>

namespace TrekStar {
    namespace People {
        class Crew
        {
        public:
            Crew();
            virtual ~Crew() = default;

        protected:
            unsigned int id;
            std::string name;
        };
    }
}

#endif //TREKSTAR_CREW_H
