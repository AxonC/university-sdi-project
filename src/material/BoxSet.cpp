#include "BoxSet.h"

namespace TrekStar {
    namespace Material {
        BoxSet::BoxSet(unsigned int id, std::string name) : Material(id, name) {}

        BoxSet::BoxSet() : Material() {}

        void BoxSet::AddDisks(const std::vector<std::shared_ptr<DVD>> & newDisks)
        {
            for (const auto &i: newDisks) {
                disks.push(*i);
            }
        }

        void BoxSet::PopulateFromFile(const std::vector<std::string> &)
        {

        }
    }
}

