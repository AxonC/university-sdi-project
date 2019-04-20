#include "BinarySearch.h"

namespace TrekStar
{
    namespace Algorithms
    {
        int binarySearch(std::vector<TrekStar::Project::Project> & list, std::string target)
        {
            int result = -1;
            int low = 0;
            int high = list.size() - 1;
            int mid;

            while ( result == -1 && low <= high )
            {
                mid = low + ((high - low) / 2);

                if ( list[mid] == target )
                {
                    result = mid;
                }
                else if( list[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }

            return result;
        }
    }
}
