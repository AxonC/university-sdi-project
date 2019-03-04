//
// Created by Matt Robinson on 2019-03-04.
//

#include "Material.h"
#include <string>

namespace TrekStar {
    namespace Material {
        /**
         *  Trekstar Material Class Implementation
         */
        int Material :: getId()
        {
            return id;
        }

        std::string Material :: getTitle()
        {
            return title;
        }

        std::string Material :: getFormat()
        {
            return format;
        }

        std::string Material :: getAudioFormat()
        {
            return audioFormat;
        }

        std::string Material :: getRunTime()
        {
            return runTime;
        }

        std::string Material :: getLanguage()
        {
            return language;
        }

        unsigned int Material :: getRetailPrice()
        {
            return retailPrice;
        }

        std::string Material :: getSubtitles()
        {
            return subtitles;
        }

        std::string Material :: getFrameAspect()
        {
            return frameAspect;
        }
    }
}