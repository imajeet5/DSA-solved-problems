// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find minimum number of attempts needed in
    //order to find the critical floor.
    int eggDrop(int n, int k)
    {
        // your code here
        // n is number of eggs and k is the total number of floors
        int dp[n + 1][k + 1] = {};
        for (int e = 1; e <= n; e++)
        {
            for (int f = 1; f <= k; f++)
            {
                if (e == 1)
                { // if we have single floor then number of trail is equal to number of floors
                    dp[e][f] = f;
                }
                else if (f == 1)
                {
                    // if there is single floor then number of trail is 1 irrespective of the number of floors
                    dp[e][f] = 1;
                }
                else
                {
                    int minVal = INT_MAX;

                    for (int cj = f - 1, pj = 0; cj >= 0; cj--, pj++)
                    {
                        int v1 = dp[e][cj];     // eggs survives
                        int v2 = dp[e - 1][pj]; // eggs breaks
                        minVal = min(max(v1, v2), minVal);
                    }

                    dp[e][f] = minVal + 1;
                }
            }
        }

        return dp[n][k];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking eggs and floors count
        int n, k;
        cin >> n >> k;
        Solution ob;
        //calling function eggDrop()
        cout << ob.eggDrop(n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends