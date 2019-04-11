#ifndef TREKSTAR_BOXSET_H
#define TREKSTAR_BOXSET_H

#include "../structures/Stack.h"
#include "DVD.h"

using TrekStar::Structures::Stack;

namespace TrekStar {
    namespace Material {
        class BoxSet: public Material::Material {
         public:
            BoxSet();
            BoxSet(unsigned int id, std::string name);

            void AddDisks(const std::vector<std::shared_ptr<DVD>> &);
            void AddDisk(const std::shared_ptr<DVD> &);
            Stack<DVD> GetDisks() const;

            void PopulateFromFile(const std::vector<std::string> &) override;
         private:
            Stack<DVD> disks;
        };
    }
}


#endif //TREKSTAR_BOXSET_H
