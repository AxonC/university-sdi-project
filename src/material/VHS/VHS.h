#ifndef TREKSTAR_VHS_H
#define TREKSTAR_VHS_H

#include "../Material/Material.h"

namespace TrekStar {
    namespace Material {
        struct SerialisedVHS
        {
            explicit SerialisedVHS(const SerialisedMaterial & baseMaterial, const std::string & audioTrack)
            {
                this->material = baseMaterial;
                this->audioTrack = audioTrack;
            }

            SerialisedMaterial material;
            std::string audioTrack;
        };

        class VHS: public Material
        {
            private:
                std::string audioTrack;
            public:
                VHS();

            std::string GetAudioTrack();
            void SetAudioTrack(const std::string &);

            KeyValueMap GetPresentableInformation() const override;
            void PopulateFromFile(const json &) override;
        };

        void to_json(json & j, const SerialisedVHS & serialisedVHS);
    }
}


#endif //TREKSTAR_VHS_H
