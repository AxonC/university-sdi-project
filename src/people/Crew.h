#ifndef TREKSTAR_CREW_H
#define TREKSTAR_CREW_H

#include <string>

namespace TrekStar {
    namespace People {
        class Crew
        {
        public:
            Crew() = default;
            Crew(unsigned int id, const std::string & name);
            virtual ~Crew() = default;

            void SetJobTitle(const std::string &);

        protected:
            unsigned int id;
            std::string name;
            std::string jobTitle;
        };
    }
}

#endif //TREKSTAR_CREW_H
