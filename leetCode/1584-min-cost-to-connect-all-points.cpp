#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int totalNodes = points.size(), cost = 0, currentPointIndex = 0, connected = 0;
        vector<bool> visited(totalNodes);
        // we will create a min heap and add all the point in the min heap
        priority_queue<pair<int, int>> pq;
        while (++connected < totalNodes)
        {
            // this point has been visited
            visited[currentPointIndex] = true;
            // now what we do is, we will pu4sh all the point that can be visited from the current points
            // in the priority queue, that are not visited yet
            // from the current nodes we can visit all the node

            for (int j = 0; j < totalNodes; j++)
            {
                if (!visited[j])
                {
                    // in the pq we will push the, weight of the edge, when visited from the currentNode and its index
                    pq.push({-(abs(points[currentPointIndex][0] - points[j][0]) + abs(points[currentPointIndex][1] - points[j][1])), j});
                }
            }
            // now what we will do is from the current point, we will take the point at the sortest distance and is not visited
            while (visited[pq.top().second])
            {
                // even if there is a point at the sortest distance but is visited we will remove that point
                pq.pop();
            }
            // so we are left with the point with min cost that is not visited
            auto minCostPoint = pq.top();
            cost -= minCostPoint.first;
            currentPointIndex = minCostPoint.second;
            pq.pop();
        }

        return cost;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};
    int result = sol.minCostConnectPoints(points);
    cout << result;
    return 0;
}