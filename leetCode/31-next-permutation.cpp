#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return;
        }
        
        // 32154
        // 32451
        // 32415

        int i = n - 2;

        // we will get the element for which current element is smaller then the predecessor
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if (i >= 0)
        {
            // then we will find the first number that is greater then the number that we have found
            int j = n - 1;
            // j will be the index of the number which is greater then the current index of the number which we have found
            while (nums[j] <= nums[i])
                j--;

            // we will swap the number
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};