// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        // we will compare all the prefixes of 1st string with the prefixes of 2nd string for the longest common suffix
        vector<vector<int>> dp(S1.length() + 1, vector<int>(S2.length() + 1, 0));
        int maxSubstr = 0;
        for (int i = 1; i < dp.size(); i++)
        {
            for (int j = 1; j < dp[0].size(); j++)
            {
                // here we will see if the last character of the current prefix of
                // both the strings are equal then or not
                char c1 = S1[i - 1];
                char c2 = S2[j - 1];
                if (c1 != c2)
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                if (dp[i][j] > maxSubstr)
                {

                    maxSubstr = dp[i][j];
                }
            }
        }

        return maxSubstr;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
