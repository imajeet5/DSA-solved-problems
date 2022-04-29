#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void DFS(int i, int j, vector<vector<char>> &grid)
    {

        // if we are going out of the bound
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
        {
            return;
        }

        // if the element if visited or if it is water
        if (grid[i][j] == '2' || grid[i][j] == '0')
        {
            return;
        }

        // make the current item as visited
        grid[i][j] = '2';

        // now do DFS in all the four directions
        DFS(i + 1, j, grid);
        DFS(i - 1, j, grid);
        DFS(i, j + 1, grid);
        DFS(i, j - 1, grid);
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int islands = 0;

        // now we will iterate over all the elements of the gird and do DFS
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                // DO DFS to find the connecting components
                if (grid[i][j] == '1')
                {
                    DFS(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}