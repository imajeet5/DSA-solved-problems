#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        // we will use the moore voting algorithm
        int count = 0;
        int candidate = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // if count becomes zero then we will update the current element
            if (count == 0)
            {
                candidate = nums[i];
            }

            if (candidate == nums[i])
                count++;
            else
                count--;
        }

        return candidate;
    }
};