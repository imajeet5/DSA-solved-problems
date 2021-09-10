#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countPaths(int m, int n, int i, int j)
    {
        if (i >= m || j >= 0)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        return countPaths(m, n, i, j + 1) + countPaths(m, n, i + 1, j);
    }

    int uniquePaths(int m, int n)
    {

        return countPaths(m, n, 0, 0);
    };
};

class Solution2
{
public:
    int countPaths(int m, int n, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = countPaths(m, n, i, j + 1, dp) + countPaths(m, n, i + 1, j, dp);
        return dp[i][j];
    }

    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return countPaths(m, n, 0, 0, dp);
    };
};

class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        int T[n][m];
        for (int i = 0; i < n; i++)
        {
            T[i][0] = 1;
        }

        for (int i = 0; i < m; i++)
        {
            T[0][i] = 1;
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                T[i][j] = T[i - 1][j] + T[i][j - 1];
            }
        }
        return T[n - 1][m - 1];
    }
};

class Solution4
{
public:
    int uniquePaths(int m, int n)
    {

        int N = m + n - 2;
        int r = m - 1;

        double res = 1;

        /*             
            10C3;            
            10*9*8/3*2*1;            
         */

        for (int i = 0; i < r; i++)
        {
            res *= (N - r + i) / i;
        }

        return (int)res;
    };
};
