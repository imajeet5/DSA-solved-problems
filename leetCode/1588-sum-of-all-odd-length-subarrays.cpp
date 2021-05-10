#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        vector<int> pref;
        pref.push_back(arr[0]);
        for (int i = 1; i < arr.size(); i++)
        {
            pref[i] = pref[i - 1] + arr[i];
        }

        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; i + j < arr.size(); j += 2)
            {
                int l = i, r = i + j;
                // so to get range sum, we have to subtract pref[l-1] from pref[r]
                int a = l - 1 > -1 ? pref[l - 1] : 0;
                int b = pref[r];
                ans = ans + b - a;
            }
        }

        return ans;
    }
};