#ifndef TREKSTAR_BINARYSEARCH_H
#define TREKSTAR_BINARYSEARCH_H

#include <vector>
#include "../model/project/Project.h"

namespace TrekStar
{
    namespace Algorithms
    {
        int binarySearch(std::vector<TrekStar::Project::Project> & list, std::string target);
    }
}

#endif //TREKSTAR_BINARYSEARCH_H
