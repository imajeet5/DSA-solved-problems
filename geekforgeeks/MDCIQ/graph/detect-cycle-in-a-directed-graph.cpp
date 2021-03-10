// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool DFS(int sv, vector<int> adj[], vector<bool> &visited, vector<bool> &inStack)
    {
        visited[sv] = true;
        inStack[sv] = true;

        vector<int> neighbors = adj[sv];
        for (int i = 0; i < neighbors.size(); i++)
        {
            int curr = neighbors[i];
            if (inStack[curr])
                return true;
            if (!visited[curr])
            {
                bool ans = DFS(curr, adj, visited, inStack);
                if (ans == true)
                    return true;
            }
        }

        inStack[sv] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<bool> inStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                bool ans = DFS(i, adj, visited, inStack);
                if (ans == true)
                    return true;
            }
        }
        return false;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}


/* 

1

3
4 2
1 2
2 3

 */
// } Driver Code Ends