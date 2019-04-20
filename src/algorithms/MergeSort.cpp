#include "MergeSort.h"

namespace TrekStar
{
    namespace Algorithms
    {
        void merge(std::vector<TrekStar::Project::Project> & list, int leftPos, int rightPos, int rightEnd)
        {
            std::vector<TrekStar::Project::Project> temp(list);

            int leftEnd = leftPos;
            int tempPos = rightPos + 1;

            for ( int i = leftPos; i <= rightEnd; i++ )
            {
                if ( leftEnd <= rightPos && (tempPos > rightEnd || (temp)[leftEnd] < (temp)[tempPos]) )
                {
                    list[i] = (temp)[leftEnd];
                    leftEnd++;
                }
                else
                {
                    list[i] = (temp)[tempPos];
                    tempPos++;
                }
            }
        }


        void sort(std::vector<TrekStar::Project::Project> & list, int low, int high)
        {
            if ( low < high )
            {
                int centre = (low + high) / 2;
                sort(list, low, centre);
                sort(list, centre + 1, high);
                merge(list, low, centre, high);
            }
        }


        void mergeSort(std::vector<TrekStar::Project::Project> & list)
        {
            sort(list, 0, (int)list.size() - 1);
        }
    }
}
