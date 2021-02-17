// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        // Code here.
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % k;
            mp[rem]++;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            int rem = nums[i] % k;
            //case1:  remainder == 0; numbers needs to be even
            if (rem == 0)
            {
                int freq = mp[rem];
                // when frequency is even
                if (freq % 2 == 1)
                {
                    return false;
                }
            }
            //case2: when remainder is half
           else if (2 * rem == k)
            {
                //frequency of remainder must be even
                int freq = mp[rem];
                if (freq % 2 == 1)
                {
                    return false;
                }
            }
            else
            {
                // frequency of the compliment must be equal
                int freq = mp[rem];
                int cfreq = mp[k - rem];
                if (freq != cfreq)
                {
                    return false;
                }
            }
        }

        return true;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++)
            cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} // } Driver Code Ends