// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minimumCostPath(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 0; j--)
            {
                // for the cornor most last element, will be called only once
                if (i == rows - 1 && j == cols - 1)
                {
                    dp[i][j] = grid[i][j];
                }
                else if (i == rows - 1)
                {
                    // this will also be called once for the bottom most row
                    // min cost for the adjacent path and its current cost
                    dp[i][j] = dp[i][j + 1] + grid[i][j];
                }
                else if (j == cols - 1)
                {
                    // this will be called every time row is changes
                    // min cost for the next bottom row and its current cost
                    dp[i][j] = dp[i + 1][j] + grid[i][j];
                }
                else
                {
                    // in all other cases check both the adjacent horizontal and vertical cells
                    dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i][j];
                }
            }
        }

        return dp[0][0];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends