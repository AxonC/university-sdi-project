//
// Created by Matt Robinson on 2019-04-16.
//

#ifndef SDI_PROJECT_VHSCONTROLLER_H
#define SDI_PROJECT_VHSCONTROLLER_H

#include "../model/material/VHS.h"

namespace TrekStar
{
    namespace Material
    {
        struct VHSView
        {
            SerialisedVHS data;
        };

        class VHSController
        {
        private:
            VHS model;

        public:
            VHSController() = default;
            ~VHSController() = default;

            static VHSView Show(const VHS & vhs);
        };
    }
}

#endif //SDI_PROJECT_VHSCONTROLLER_H
