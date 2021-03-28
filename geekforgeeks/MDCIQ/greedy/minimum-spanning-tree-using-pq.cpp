#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int selectMinCostVertex(vector<int> minCost, vector<int> isDone, int V)
    {
        int minimun = INT_MAX;
        int vertex;
        for (int i = 0; i < V; i++)
        {
            if (!isDone[i] && minCost[i] < minimun)
            {
                minimun = minCost[i];
                vertex = i;
            }
        }

        return vertex;
    }
    // Function to construct and print MST for
    // a graph represented using adjacency
    // list representation, with V vertices.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        set<pair<int, pair<int, int>>> s;
        vector<int> visited(V, false);
        int sum = 0;
        // current node, parent node and weigh of visiting from current to parent
        s.insert({0, {0, -1}});

        while (!s.empty())
        {
            auto currMinCost = *(s.begin());
            int currNode = currMinCost.second.first;
            int currParent = currMinCost.second.second;
            int currWeight = currMinCost.first;
            s.erase(s.begin());
            if (visited[currNode])
            {
                continue;
            }
            visited[currNode] = true;
            sum += currWeight;

            // now visit all the adjacent nodes of of current
            // and for any vertex that is not done yet, if the distance from current is smaller then it's current distance
            // then we update it parent as current
            auto neighbour = adj[currNode];
            for (int j = 0; j < neighbour.size(); j++)
            {
                vector<int> node = neighbour[j];
                int nodeVal = node[0];
                int nodeWeight = node[1];
                if (!visited[nodeVal])
                {
                    s.insert({nodeWeight, {nodeVal, currNode}});
                }
            }
        }

        return sum;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends