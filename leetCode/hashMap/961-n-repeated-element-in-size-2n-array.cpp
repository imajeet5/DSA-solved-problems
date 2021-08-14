#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++)
        {
            freq[nums[i]]++;
            if (freq[nums[i]] == (nums.size() / 2))
            {
                return nums[i];
            }
        }
    }
};