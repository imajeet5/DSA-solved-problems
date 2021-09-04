#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findFirstIndex(vector<int> &nums, int target)
    {
        int index = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int midPoint = start + (end - start) / 2;

            // as this function will return the first index, so if the value at mid point
            // is greater then or equal then end point will be midpoint-1
            if (nums[midPoint] >= target)
            {
                end = midPoint - 1;
            }
            else
            {
                start = midPoint + 1;
            }
            if (nums[midPoint] == target)
            {
                index = midPoint;
            }
        }

        return index;
    }

    int findEndIndex(vector<int> &nums, int target)
    {
        int index = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int midPoint = start + (end - start) / 2;

            if (nums[midPoint] <= target)
            {
                start = midPoint + 1;
            }
            else
            {
                end = midPoint - 1;
            }

            if (nums[midPoint] == target)
            {
                index = midPoint;
            }
        }

        return index;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {

        vector<int> result = {-1, -1};

        result[0] = findFirstIndex(nums, target);
        result[1] = findEndIndex(nums, target);

        return result;
    }
};