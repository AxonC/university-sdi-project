#ifndef TREKSTAR_DVDVIEW_H
#define TREKSTAR_DVDVIEW_H

#include "MaterialView.h"
#include "../../model/material/DVD.h"
#include "../../model/material/DVDInterface.h"

namespace TrekStar
{
    namespace Material
    {
        class DVDView : public MaterialView
        {
        private:
            DVD* GetModel() override;

        public:
            explicit DVDView(DVD & model);

            std::string GetNewContent();
            unsigned int GetUpdateOption() override;
        };
    }
}

#endif //TREKSTAR_DVDVIEW_H
