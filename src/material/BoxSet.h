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
            Stack<std::shared_ptr<Material>> GetDisks() const;

            KeyValueMap GetPresentableInformation() const override;
            void PopulateFromFile(const json &) override;
         private:
            Stack<std::shared_ptr<Material>> disks;
        };
    }
}


#endif //TREKSTAR_BOXSET_H
