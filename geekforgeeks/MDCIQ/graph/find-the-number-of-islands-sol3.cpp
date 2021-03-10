// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool shouldCheck(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        int n = grid.size();
        int m = grid[0].size();
        return (i >= 0) && (i < n) && (j >= 0) && (j < m) && !visited[i][j] && grid[i][j] == '1';
    }

    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        // this array represents all the direction from the current origin
        int rowNbr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int colNbr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        visited[i][j] = true;

        for (int k = 0; k < 8; k++)
        {
            if (shouldCheck(grid, i + rowNbr[k], j + colNbr[k], visited))
            {
                dfs(grid, i + rowNbr[k], j + colNbr[k], visited);
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends