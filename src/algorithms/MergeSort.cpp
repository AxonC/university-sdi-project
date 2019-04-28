#include "MergeSort.h"

namespace TrekStar
{
    namespace Algorithms
    {
        /**
           Function Name: merge

           Responsible for performing the merge operation on a vector of Projects that has been split in to sublists.

           @param Vector of Project objects.
           @param Index of the first item in the left sublist.
           @param Index of the first item in the right sublist.
           @param Index of the last item in the right sublist.
        */
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


        /**
           Function Name: sort

           Responsible for calling the merge function until the vector of projects is sorted.

           @param Vector of Project objects.
           @param Index of the first item in the vector.
           @param Index of the last item in the vector.
        */
        void sort(std::vector<TrekStar::Project::Project> & list, int low, int high)
        {
            // If the vector is unsorted.
            if ( low < high )
            {
                int centre = (low + high) / 2;   // Find the index of the middle Project.
                sort(list, low, centre);         // Perform sorting on the left half of the vector.
                sort(list, centre + 1, high);    // Perform sorting on the right half of the vector.
                merge(list, low, centre, high);  // Merge the two halves together.
            }
        }


        /**
          Function Name: mergeSort

          Responsible for calling the sort function with the correct parameters. This is completed in-place, so no
          return value is required.

          @param Vector of Project objects.
        */
        void mergeSort(std::vector<TrekStar::Project::Project> & list)
        {
            sort(list, 0, (int)list.size() - 1);
        }
    }
}
