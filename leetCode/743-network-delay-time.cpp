#include <bits/stdc++.h>

using namespace std;

class SolutionUsingBFS
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // first will will create the graph
        // for that as we have nodes from 0 to n we will create a graph 2d array of n+1 as 0th will not be in use
        //   0      1    2                3
        // [[{}], [{}], [{1,1}, {3,1}]  [{4,1}]]
        vector<pair<int, int>> g[n + 1];
        // for we will create the graph
        for (int i = 0; i < times.size(); i++)
        {
            // this is the source
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        // we will create a distance array which have all the values inital to infinite
        vector<int> dist(n + 1, INT_MAX);

        // we k is the source node we will mark it distance as 0
        dist[k] = 0;
        // this will store the node and it's distance from the root node, using the queue we will do the BFS
        queue<int> q;
        q.push(k);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto next : g[curr])
            {
                // if stored distance of the next node is greater than the stored distance of the current node plus 
                //distance from current node to the next node, then override it
                if (dist[next.first] > dist[curr] + next.second)
                {
                    dist[next.first] = dist[curr] + next.second;
                    q.push(next.first);
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                // we have a un-visited node
                return -1;
            }

            res = max(res, dist[i]);
        }

        return res;
    }
};

class SolutionDijkstra
{
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // creating graph
        vector<pair<int, int>> g[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            g[times[i][0]].push_back({times[i][1], times[i][2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // first -> distance, second -> value
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // as k is the source node
        pq.push({0, k});
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            // now iterate over all the adjacent/next node of the current and check their distance
            for (auto next : g[curr.second])
            {
                // if the store distance of the next node is greater than the distance of the current node along the path(which 
                //is the minimum distance) plus distance from current node to the next node then override it
                if (dist[next.first] > curr.first + next.second)
                {
                    dist[next.first] = curr.first + next.second;
                    pq.push({next.first, dist[next.first]});
                }
            }
        }

        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
            {
                // we have a un-visited node
                return -1;
            }

            res = max(res, dist[i]);
        }

        return res;
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