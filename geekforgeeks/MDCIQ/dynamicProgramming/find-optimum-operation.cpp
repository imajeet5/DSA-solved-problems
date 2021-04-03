// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minOperation(int n)
    {
        //code here.
        int dp[n + 1];
        for (int i = 0; i <= n; i++)
        {
            if (i == 0)
            {
                dp[0] = 0;
                continue;
            }
            if (i == 1)
            {
                dp[1] = 1;
                continue;
            }
            //if i is even
            if (i % 2 == 0)
            {
                dp[i] = dp[i / 2] + 1;
            }
            else
            {
                // if i is odd
                dp[i] = dp[i - 1] + 1;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperation(n) << endl;
    }
} // } Driver Code Ends