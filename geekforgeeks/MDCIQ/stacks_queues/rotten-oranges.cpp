// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++

// matrix : given matrix
// R and C : number of rows and columns respectively

int rotOranges(vector<vector<int>> &matrix, int R, int C)
{
    // Your code goes here
    set<pair<int, int>> fresh;
    set<pair<int, int>> rotten;
    // storing the coordinates of rotten and fresh oranges
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 1)
            {
                fresh.insert(make_pair(i, j));
            }
            else if (matrix[i][j] == 2)
            {
                rotten.insert(make_pair(i, j));
            }
        }
    }

    int minutes = 0;
    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    while (fresh.size() > 0)
    {
        set<pair<int, int>> infected;
        for (auto coord : rotten)
        {
            int x = coord.first;
            int y = coord.second;
            for (auto dir : directions)
            {
                int nextX = x + dir[0];
                int nextY = y + dir[1];
                auto nearBy = make_pair(nextX, nextY);
                // check if the nearby are fresh oranges
                if (fresh.find(nearBy) != fresh.end())
                {
                    // remove from fresh and add to nearby
                    fresh.erase(nearBy);
                    infected.insert(nearBy);
                }
            }
        }
        // if we have fresh oranges and none of the fresh orange is infected in the iteration
        if (infected.size() == 0)
        {
            return -1;
        }
        // as all the nearBy to current rotten are infected to infected becomes the new rotten
        rotten = infected;
        minutes++;
    }
    return minutes;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> matrix(R);
        for (int i = 0; i < R; ++i)
        {
            matrix[i].resize(C);
            for (int j = 0; j < C; ++j)
                cin >> matrix[i][j];
        }
        cout << rotOranges(matrix, R, C) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
1
3 5
2 1 0 2 1 1 0 1 2 1 1 0 0 2 1
*/