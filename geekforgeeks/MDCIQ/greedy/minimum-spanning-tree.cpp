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
        // code here
        int parent[V];
        vector<int> minCost(V, INT_MAX);
        vector<int> isDone(V, false);
        int sum = 0;

        // setting parent of 0  as -1
        parent[0] = -1;
        minCost[0] = 0;

        for (int i = 0; i < V ; i++)
        {
            // now select the value having minimum cost from the graph which is not done
            int curr = selectMinCostVertex(minCost, isDone, V);
            isDone[curr] = true;

            // now visit all the adjacent nodes of of current
            // and for any vertex that is not done yet, if the distance from current is smaller then it's current distance
            // then we update it parent as current
            auto neighbour = adj[curr];
            for (int j = 0; j < neighbour.size(); j++)
            {
                vector<int> node = neighbour[j];
                int nodeVal = node[0];
                int nodeWeight = node[1];
                if (isDone[nodeVal] == false && nodeWeight < minCost[nodeVal])
                {
                    minCost[nodeVal] = nodeWeight;
                    parent[nodeVal] = curr;
                }
            }
        }

        for (int i = 1; i < V; i++)
        {
            int parentNode = parent[1];
            auto neighbour = adj[parentNode];
            for (int j = 0; j < neighbour.size(); j++)
            {
                int val = neighbour[j][0];
                int weight = neighbour[j][1];
                if (val == V)
                {
                    sum += weight;
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