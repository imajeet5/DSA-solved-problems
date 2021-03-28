// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> s;
        vector<int> dist(V + 1, INT_MAX);
        s.insert(make_pair(0, S));
        dist[S] = 0;
        while (!s.empty())
        {
            // get the lowest distance element from the set
            pair<int, int> p_sortest = *(s.begin());
            int p_val = p_sortest.second;
            // remove that element from the set
            s.erase(s.begin());

            vector<vector<int>> neighbors = adj[p_val];

            for (int i = 0; i < neighbors.size(); i++)
            {
                auto curr = neighbors[i];  
                int v = curr[0];
                int weight = curr[1];

                if (dist[p_val] + weight < dist[v])
                {
                    // if the element pair is already present in the set we will delete it
                    if (dist[v] != INT_MAX)
                    {
                        s.erase(s.find(make_pair(dist[v], v)));
                    }

                    dist[v] = dist[p_val] + weight;
                    s.insert(make_pair(dist[v], v));
                }
            }
        }

        return dist;
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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends