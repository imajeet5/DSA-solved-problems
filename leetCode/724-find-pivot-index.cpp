#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int total = 0;
        int currSum = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                currSum += nums[i - 1];
            int rem = total - currSum - nums[i];
            if (currSum == rem)
            {
                return i;
            }
        }

        return -1;
    }
};