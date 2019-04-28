#include "BinarySearch.h"

namespace TrekStar
{
    namespace Algorithms
    {
        /**
          Function Name: binarySearch

          Responsible for performing binary search on a vector of Projects.

          @param The index of the target Project, or -1 if the target could not be found.
        */
        unsigned int binarySearch(std::vector<TrekStar::Project::Project> & list, std::string target)
        {
            int result = -1;             // Set result to not found.
            int low = 0;                 // Set low to the index of the first Project in the vector.
            int high = list.size() - 1;  // Set high to the index of the last Project in the vector.
            int mid;

            // While the result is not found and not all items have been checked.
            while ( result == -1 && low <= high )
            {
                mid = low + ((high - low) / 2);

                if ( list[mid] == target )  // If the middle item is the target.
                {
                    result = mid;
                }
                else if ( list[mid] < target )  // If the target is on the left.
                {
                    low = mid + 1;
                }
                else  // If the target is on the right.
                {
                    high = mid - 1;
                }
            }

            return result;
        }
    }
}
