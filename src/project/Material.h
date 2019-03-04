//
// Created by Matt Robinson on 2019-03-04.
//

#ifndef TREKSTAR_MATERIAL_H
#define TREKSTAR_MATERIAL_H

#include <string>

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar Material Class
         */
        class Material
        {
            private:
                unsigned int id;
                std::string title;
                std::string format;
                std::string audioFormat;
                std::string runTime;
                std::string language;
                unsigned long int retailPrice; // stored in pence
                std::string subtitles;
                std::string frameAspect;
            public:
                Material() = default;
                ~Material() = default;

                int getId();
                std::string getTitle();
                std::string getFormat();
                std::string getAudioFormat();
                std::string getRunTime();
                std::string getLanguage();
                unsigned int getRetailPrice();
                std::string getSubtitles();
                std::string getFrameAspect();
        };
    }
}

#endif //TREKSTAR_MATERIAL_H
