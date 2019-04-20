#ifndef TREKSTAR_MERGESORT_H
#define TREKSTAR_MERGESORT_H

#include <vector>
#include "../model/project/Project.h"

namespace TrekStar
{
    namespace Algorithms
    {
        void merge(std::vector<TrekStar::Project::Project> & list, int leftPos, int rightPos, int rightEnd);
        void sort(std::vector<TrekStar::Project::Project> & list, int low, int high);
        void mergeSort(std::vector<TrekStar::Project::Project> & list);
    }
}

#endif //TREKSTAR_MERGESORT_H
