// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int v,
             bool visited[], int parent, vector<int> adj[])
    {

        // Mark the current node as visited
        visited[v] = true;

        vector<int> neigbours = adj[v];

        for (int i = 0; i < neigbours.size(); i++)
        {
            int curr = neigbours[i];
            // If an adjacent is not visited,
            //then recur for that adjacent
            if (!visited[curr])
            {
                if (dfs(curr, visited, v, adj))
                    return true;
            }

            // If an adjacent is visited and
            // not parent of current vertex,
            // then there is a cycle.
            else if (curr != parent)
                return true;
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Call the recursive helper
        // function to detect cycle in different
        // DFS trees
        for (int u = 0; u < V; u++)
        {

            // Don't recur for u if
            // it is already visited
            if (!visited[u])
                if (dfs(u, visited, -1, adj))
                    return true;
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends