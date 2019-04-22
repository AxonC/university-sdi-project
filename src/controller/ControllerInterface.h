#ifndef TREKSTAR_CONTROLLERINTERFACE_H
#define TREKSTAR_CONTROLLERINTERFACE_H

namespace TrekStar
{
    namespace Controller
    {
        class ControllerInterface
        {
        public:
            virtual ~ControllerInterface() = default;
            virtual void ShowAll() = 0;
            virtual void ShowList() = 0;
        };
    }
}

#endif //TREKSTAR_CONTROLLERINTERFACE_H
