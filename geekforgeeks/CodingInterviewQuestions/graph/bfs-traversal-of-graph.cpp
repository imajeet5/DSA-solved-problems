// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printBSF(int sv, vector<int> adj[], vector<bool> &visited, vector<int> ans)
    {
        queue<int> q;
        q.push(sv);
        visited[sv] = true;
        while (!q.empty())
        {
            int curr = q.front();
            ans.push_back(curr);
            q.pop();
            vector<int> neighbors = adj[curr];
            for (int i = 0; i < neighbors.size(); i++)
            {
                if (!visited[neighbors[i]])
                {
                    visited[neighbors[i]] = true;
                    q.push(neighbors[i]);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> ans;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                printBSF(i, adj, visited, ans);
        }
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
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends