
#include <bits/stdc++.h>

using namespace std;

// so we have to find the max sum of any subsequence of the array

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int currSum = nums[0];
        int maxS = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            // if the current sum is positive it is good for the next element to combine with the current sum
            if (currSum >= 0)
            {
                currSum += nums[i];
            }
            // otherwise the next element will start it's own sequence
            else
            {
                currSum = nums[i];
            }
            if (currSum > maxS)
            {
                maxS = currSum;
            }
        }
        return maxS;
    }
};