// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int editDistance(string s, string t)
    {
        // Code here
        int n = t.length(); // final string in rows
        int m = s.length(); // initial string in cols
        // int dp[n + 1][m + 1] = {};
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // operations to covert initial string to ""
        for (int i = 0; i <= m; i++)
        {
            dp[0][i] = i;
        }
        // operation to convert "" to final string
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                // if last character of both the string is same
                if (t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    // we will take min of the adjacent cells and add one to it
                    // cost of replace
                    int Cr = dp[i - 1][j - 1];
                    // const of delete
                    int Cd = dp[i][j - 1];
                    // cost of insert
                    int Ci = dp[i - 1][j];
                    int minCost = min(Cr, min(Cd, Ci));
                    dp[i][j] = minCost + 1;
                }
            }
        }

        return dp[n][m];
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends

/* 
1
geek 
gesek 
 */