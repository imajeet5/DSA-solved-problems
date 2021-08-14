#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {

        int n = s.size();
        // vector<vector<int>> vec( n , vector<int> (m, 0));
        // bool dp[n][n] = {0};
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int count = 0;
        // we will traverse all the diagonals
        for (int d = 0; d < n; d++)
        {
            // this for loop will traverse each diagonal one by one
            for (int row = 0, col = d; col < n; row++, col++)
            {
                // if this is 0th diagonal
                if (d == 0)
                {
                    dp[row][col] = 1;
                }
                else if (d == 1)
                {
                    dp[row][col] = s[row] == s[col];
                }

                else
                {
                    dp[row][col] = (s[row] == s[col]) && dp[row + 1][col - 1];
                }
                if (dp[row][col])
                {
                    count++;
                }
            }
        }

        return count;
    }
};