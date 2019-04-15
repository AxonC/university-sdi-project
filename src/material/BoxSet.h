#ifndef TREKSTAR_BOXSET_H
#define TREKSTAR_BOXSET_H

#include "../structures/Stack.h"
#include "DVD.h"

using TrekStar::Structures::Stack;
using KeyValueMapVector = std::vector<std::map<std::string, std::string>>;

namespace TrekStar {
    namespace Material {
        struct SerialisedBoxSet : public SerialisedMaterial {
            std::vector<std::shared_ptr<TrekStar::Material::Material>> dvds;
        };


        class BoxSet: public Material::Material {
         public:
            BoxSet() = default;
            BoxSet(unsigned int id, std::string name);

            void AddDisks(const std::vector<std::shared_ptr<DVD>> &);
            void AddDisk(const std::shared_ptr<DVD> &);
            Stack<std::shared_ptr<Material>> GetDisks() const;

            SerialisedBoxSet ExportToSerialised();
            KeyValueMap GetPresentableInformation() const override;
            KeyValueMapVector GetPresentableDiskInformation() const;
            void PopulateFromFile(const json &) override;
         private:
            Stack<std::shared_ptr<Material>> disks;
        };

        void to_json(const SerialisedBoxSet & dvd, const std::shared_ptr<Material> & materialObject);
        void from_json(const json & json, SerialisedBoxSet & dvd);
    }
}


#endif //TREKSTAR_BOXSET_H
