#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int time = 0;
        auto p1 = points[0];
        for (int i = 1; i < points.size(); i++)
        {
            auto p2 = points[i];
            int dx = abs(p2[0] - p1[0]);
            int dy = abs(p2[1] - p1[1]);
            time += max(dx, dy);
            p1 = p2;
        }

        return time;
    }
};