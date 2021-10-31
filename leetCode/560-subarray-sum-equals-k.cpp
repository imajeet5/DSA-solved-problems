#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {

        int count = 0;
        int pSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            pSum += nums[i];

            int rem = pSum - k;

            if (mpp.find(rem) != mpp.end())
            {
                // remaining value exist in the hash map then we can say we have a sub array in between that has sum equals to k
                count += mpp[rem];
            }
            else
            {
                // we will increase the frequency of the element in the map
                mpp[pSum]++;
            }
        }

        return count;
    }
};