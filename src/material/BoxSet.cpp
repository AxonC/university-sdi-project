//
// Created by Callum Axon on 2019-04-03.
//

#include "BoxSet.h"

namespace TrekStar {
    namespace Material {
        BoxSet::BoxSet(unsigned int id, std::string name) : Material(id, name) {}

        void BoxSet::AddDisks(const std::vector<std::shared_ptr<DVD>> & newDisks)
        {
            for (const auto &i: newDisks) {
                disks.push(*i);
            }
        }
    }
}

