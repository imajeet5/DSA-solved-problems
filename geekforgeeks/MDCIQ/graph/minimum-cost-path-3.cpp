// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool insideGrid(int x, int y, int rows, int cols)
    {
        return (x >= 0 && x < rows && y >= 0 && y < cols);
    }

    int minimumCostPath(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
        dist[0][0] = grid[0][0];
        // {{x, y}, dist}

        set<pair<pair<int, int>, int>> st;
        st.insert({{0, 0}, grid[0][0]});

        while (!st.empty())
        {
            auto curr = *st.begin();
            auto curr_coord = curr.first;
            int curr_dist = curr.second;
            st.erase(st.begin());
            for (int i = 0; i < 4; i++)
            {
                int x = curr_coord.first + dx[i];
                int y = curr_coord.second + dy[i];
                if (!insideGrid(x, y, rows, cols))
                {
                    continue;
                }
                // if the distance on visiting the adjecenent cell is smaller then it already distance from the source
                // which may be infinite if not visited or some distance if visited
                if (dist[curr_coord.first][curr_coord.second] + grid[x][y] < dist[x][y])
                {
                    // then element is already present in the set and we need to erase it
                    if (dist[x][y] != INT_MAX)
                    {
                        st.erase(st.find({{x, y}, dist[x][y]}));
                    }

                    dist[x][y] = dist[curr_coord.first][curr_coord.second] + grid[x][y];
                    st.insert({{x, y}, dist[x][y]});
                }
            }
        }

        return dist[rows - 1][cols - 1];
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