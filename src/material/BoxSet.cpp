#include "BoxSet.h"

namespace TrekStar {
    namespace Material {
        BoxSet::BoxSet(unsigned int id, std::string name) : Material(id, name) {}

        BoxSet::BoxSet() : Material() {}

        void BoxSet::AddDisks(const std::vector<std::shared_ptr<DVD>> & newDisks)
        {
            for (const auto &i: newDisks) {
                this->disks.push(*i);
            }
        }

        void BoxSet::PopulateFromFile(const std::vector<std::string> & attributes)
        {
            this->id = static_cast<unsigned int>(std::stoi(attributes.at(1)));
            this->title = attributes.at(2);
            this->retailPrice = std::stod(attributes.at(3));
        }

        void BoxSet::AddDisk(const std::shared_ptr<DVD> & disk)
        {
            this->disks.push(*disk);
        }

        Stack<DVD> BoxSet::GetDisks() const
        {
            return this->disks;
        }
    }
}

