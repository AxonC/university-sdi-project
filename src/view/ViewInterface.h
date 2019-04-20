#ifndef TREKSTAR_VIEWINTERFACE_H
#define TREKSTAR_VIEWINTERFACE_H

namespace TrekStar
{
    namespace View
    {
        class ViewInterface
        {
        public:
            virtual ~ViewInterface() = default;
            virtual void Present() = 0;
        };
    }
}

#endif //TREKSTAR_VIEWINTERFACE_H
