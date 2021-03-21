// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isSafe(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] != 0 && !visited[i][j])
        {

            return true;
        }
        return false;
    }

    bool isPath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited)
    {
        if (isSafe(grid, i, j, visited))
        {
            visited[i][j] = true;
            if (grid[i][j] == 2)
            {
                return true;
            }
            // visited all four directions
            return isPath(grid, i - 1, j, visited) || isPath(grid, i, j - 1, visited) || isPath(grid, i + 1, j, visited) || isPath(grid, i, j + 1, visited);
        }
        return false;
    }

    bool is_Possible(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited(rows, vector<int>(cols, 0));

        //traverse to the starting point of the matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 1)
                {
                    if (isPath(grid, i, j, visited))
                    {
                        return true;
                    }
                }
            }
        }

        return false;
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
        bool ans = obj.is_Possible(grid);
        cout << ((ans) ? "1\n" : "0\n");
    }
    return 0;
} // } Driver Code Ends