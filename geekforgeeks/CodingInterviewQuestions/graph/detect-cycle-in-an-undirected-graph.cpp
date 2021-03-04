// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int sv, vector<int> adj[], set<int> &visited, int parent)
    {
        visited.insert(sv);

        vector<int> neighbour = adj[sv];
        for (int i = 0; i < neighbour.size(); i++)
        {  int curr = neighbour[i];
            if (visited.count(curr) == 0)
            {
                bool ans = dfs(curr, adj, visited, sv);
                if (ans)
                    return ans;
            }
            else if (curr != parent)
            {
                return true;
            }
        }
        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here

        set<int> visited;
        for (int i = 0; i < V; i++)
        {
            if (visited.count(i) == 0)
            {
                bool ans = dfs(i, adj, visited, -1);
                if (ans)
                    return ans;
            }
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