#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        vector<int> num_copy;
        for (int i = 0; i < nums.size(); i++)
        {
            num_copy.push_back(nums[i]);
        }
        sort(num_copy.begin(), num_copy.end());

        unordered_map<int, int> sm;

        for (int i = 0; i < num_copy.size(); i++)
        {
            if (sm.find(num_copy[i]) == sm.end())
            {
                sm[num_copy[i]] = i;
            }
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            ans.push_back(sm[nums[i]]);
        }
        return ans;
    }
};