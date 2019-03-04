#ifndef PROJECT_PROJECTINTERFACE_H
#define PROJECT_PROJECTINTERFACE_H

namespace TrekStar {
    namespace Project {
        class ProjectInterface
        {
        public:
            virtual ~ProjectInterface() = default;
            virtual std::string GetSummary() const = 0;
            virtual void SetSummary(std::string) {};
        };
    }
}

#endif //PROJECT_PROJECTINTERFACE_H
