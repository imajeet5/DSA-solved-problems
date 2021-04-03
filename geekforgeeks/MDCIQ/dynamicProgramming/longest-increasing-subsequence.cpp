// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // return length of longest strictly increasing subsequence

    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n, 0);

        int totalMax = 0;
        for (int i = 0; i < n; i++)
        {
            int localMax = 0;

            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i] && dp[j] > localMax)
                {
                    localMax = dp[j];
                }
            }

            dp[i] = localMax + 1;
            totalMax = max(dp[i], totalMax);
        }

        return totalMax;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int a[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
// } Driver Code Ends