#ifndef TREKSTAR_BOXSET_H
#define TREKSTAR_BOXSET_H

#include "../../structures/Stack.h"
#include "DVD.h"

using TrekStar::Structures::Stack;
using KeyValueMapVector = std::vector<std::map<std::string, std::string>>;

namespace TrekStar
{
    namespace Material
    {
        struct SerialisedBoxSet
        {
            explicit SerialisedBoxSet(const SerialisedMaterial & baseMaterial, const std::vector<std::shared_ptr<Material>> & dvds)
            {
                this->dvds = dvds;
                this->material = baseMaterial;
            }
            SerialisedMaterial material;
            std::vector<std::shared_ptr<Material>> dvds;
        };

        class BoxSet: public Material
        {
        private:
            Stack<std::shared_ptr<Material>> disks;

        public:
            BoxSet() = default;

            void PopulateFromFile(const json &) override;

            void AddDisks(const std::vector<std::shared_ptr<DVD>> &);
            void AddDisk(const std::shared_ptr<DVD> &);

            Stack<std::shared_ptr<Material>> GetDisks() const;
            KeyValueMap GetPresentableInformation() const override;
            KeyValueMapVector GetPresentableDiskInformation() const;

            std::shared_ptr<SerialisedBoxSet> ExportToSerialised();
        };

        void to_json(json & j, const SerialisedBoxSet & serialisedBoxSet);
        void from_json(const json & json, SerialisedBoxSet & dvd);
    }
}


#endif //TREKSTAR_BOXSET_H
