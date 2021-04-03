// { Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    int lcs(int x, int y, string s1, string s2)
    {
        // create a dp with all element initialized to 0
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        // run loop from the last index
        for (int i = x - 1; i >= 0; i--)
        {
            for (int j = y - 1; j >= 0; j--)
            {
                char c1 = s1[i];
                char c2 = s2[j];
                // there will be two cases
                //1. c1 == c2
                if (c1 == c2)
                {
                    // go diagonally and add 1
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    // we will take max of value at bottom and left
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    int t, n, k, x, y;
    cin >> t;
    while (t--)
    {
        cin >> x >> y; // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
// } Driver Code Ends