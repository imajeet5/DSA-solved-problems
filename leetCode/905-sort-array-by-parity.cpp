#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        // so we have to move all the even integer at the start of the string
        // we will take two pointer i, which only move when we have an even integer and j move with the loop
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            // if the current number is even
            // then we swap it with the ith position element and move i
            if (nums[j] % 2 == 0)
            {
                swap(nums[i], nums[j]);
                i++;
            }
        }

        return nums;
    }
};