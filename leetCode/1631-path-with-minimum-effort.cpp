#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector<vector<int>> dirs = {
        {-1, 0},
        {0, -1},
        {0, 1},
        {1, 0}};

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        using pipii = pair<int, pair<int, int>>;
        priority_queue<pipii, vector<pipii>, greater<pipii>> pq;

        int ROWS = heights.size();
        int COLS = heights[0].size();

        // all the elements are inital to infinite
        vector<vector<int>> minEfforts(ROWS, vector<int>(COLS, INT_MAX));

        minEfforts[0][0] = 0;

        pq.push({0, {0, 0}});
        while (!pq.empty())
        {
            auto current = pq.top();
            pq.pop();

            int currentEffort = current.first;
            auto coords = current.second;
            int r = coords.first;
            int c = coords.second;
            if (minEfforts[r][c] < currentEffort)
                continue;
            if (r == ROWS - 1 && c == COLS - 1)
                return currentEffort;

            // visite all the adjacent children
            for (auto &dir : dirs)
            {
                int dr = r + dir[0];
                int dc = c + dir[1];
                if (dr < 0 || dr >= ROWS)
                    continue;
                if (dc < 0 || dc >= COLS)
                    continue;
                int newEffort = abs(heights[r][c] - heights[dr][dc]);
                newEffort = max(newEffort, currentEffort);
                if (minEfforts[dr][dc] <= newEffort)
                {
                    minEfforts[dr][dc] = newEffort;
                    pq.push({newEffort, {dr, dc}});
                }
            }
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;
    vector<vector<int>> heights = {{1, 2, 3}, {3, 8, 4}, {5, 3, 5}};
    int result = sol.minimumEffortPath(heights);

    cout << "Result: " << result << endl;
    return 0;
}