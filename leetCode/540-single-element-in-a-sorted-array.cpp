#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        // in this we will do binary search
        int low = 0;
        // we take high as one less bcz high can be the last index
        int high = nums.size() - 2;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            // we will check if the mid is in left half, for mid to be in the left half
            // 1st Instance => even
            // 2nd Instance => odd
            // we will use XOR, if mid is even mid^1 will give next odd index
            // and if mid is odd then mid^1 give the previous even index
            if (nums[mid] == nums[mid ^ 1])
            {
                // we will shrink the left search space if it is in the left side
                low = mid + 1;
            }
            else
            {
                // we will shrink the right space if it is in the right half
                high = mid + 1;
            }
        }
        return nums[low];
    }
};