#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;
        int rows = grid.size(), cols = grid[0].size();
        // we will use queue for bfs, we will store the coordinates of the rotten oranges in the
        // queue
        queue<pair<int, int>> rotten;
        // total oranges include rotten and fresh oranges
        // we will count the total oranges and if in the end cnt and total oranges are not equal,
        // then we are not able to convert all the oranges

        int totalOranges = 0, minutes = 0, cnt = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] != 0)
                    totalOranges++;
                if (grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!rotten.empty())
        {
            // the current elements in the queue will make rotten the other element
            // we will get the current element in the queue
            int currentRotten = rotten.size();

            cnt += currentRotten;

            while (currentRotten--)
            {
                // we will take the first element of the queue
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                // for every element we will move all the four directions
                for (int i = 0; i < 4; i++)
                {
                    // first we will check if the movement is possible
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] != 1)
                        continue;
                    // we will make the orange rotten
                    grid[nx][ny] = 2;
                    // otherwise push the next coordinates into rotten as this is going to be rotten in the next iteration
                    rotten.push({nx, ny});
                }
            }

            // if we have rotten oranges we will increase the minutes count
            if (!rotten.empty())
                minutes++;
        }

        return totalOranges == cnt ? minutes : -1;
    }
};