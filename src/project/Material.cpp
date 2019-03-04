//
// Created by Matt Robinson on 2019-03-04.
//

#include "Material.h"

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar Material Class Implementation
         */
        int getId()
        {
            return id;
        }

        std::string getTitle()
        {
            return title;
        }

        std::string getFormat()
        {
            return format;
        }

        std::string getAudioFormat()
        {
            return audioFormat;
        }

        std::string getRunTime()
        {
            return runTime;
        }

        std::string getLanguage()
        {
            return language;
        }

        unsigned int getRetailPrice()
        {
            return retailPrice;
        }

        std::string getSubtitles()
        {
            return subtitles;
        }

        std::string getFrameAspect()
        {
            return frameAspect;
        }
    }
}