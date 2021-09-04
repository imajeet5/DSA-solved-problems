#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int start = 0;
        int end = nums.size();

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }

            // check if the left half is sorted
            if (nums[start] <= nums[mid])
            {
                // check if the element exist in the left half
                if (target >= nums[start] && target <= nums[mid])
                {
                    // we will discard the right half
                    end = mid - 1;
                }
                else
                {
                    // if the element is not present the sorted half then we will discard the current half
                    start = mid + 1;
                }
            }
            else
            {
                // if the right half is sorted
                if (target >= nums[mid] && target <= nums[end])
                {
                    // if the element is the in the right half, then we will discard the left half
                    start = mid + 1;
                }
                else
                {
                    // if the element not present in this half
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};