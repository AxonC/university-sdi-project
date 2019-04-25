#ifndef TREKSTAR_VHS_H
#define TREKSTAR_VHS_H

#include "Material.h"

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
                std::vector<std::string> permittedPackaging;
                std::string audioTrack;
            public:
                VHS();

                std::string GetAudioTrack();
                std::vector<std::string> GetPermittedPackaging() const;

                void SetAudioTrack(const std::string &);

                KeyValueMap GetPresentableInformation() const override;
                std::shared_ptr<SerialisedVHS> ExportToSerialised() const;

                void PopulateFromFile(const json &) override;
        };

        void to_json(json & j, const SerialisedVHS & serialisedVHS);
    }
}


#endif //TREKSTAR_VHS_H
