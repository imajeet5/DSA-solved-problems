// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*  Function to find the number of strongly connected components
    *   using Kosaraju's algorithm
    *   V: number of vertices
    *   adj[]: array of vectors to represent graph
    */

    void dfs(int sv, stack<int> &s, vector<bool> &visited, vector<int> adj[])
    {
        visited[sv] = true;
        vector<int> neighbors = adj[sv];
        for (int i = 0; i < neighbors.size(); i++)
        {
            int curr = neighbors[i];
            if (!visited[curr])
            {
                dfs(curr, s, visited, adj);
            }
        }
        s.push(sv);
    }

    void dfs2(int sv, vector<bool> &visited, vector<int> adj[])
    {
        visited[sv] = true;
        vector<int> neigbours = adj[sv];
        for (int i = 0; i < neigbours.size(); i++)
        {
            int curr = neigbours[i];
            if (!visited[curr])
            {
                dfs2(curr, visited, adj);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //Step 1: push the element of the graph in stack while backtracking
        vector<bool> visited1(V, false);
        stack<int> s;
        for (int i = 0; i < V; i++)
        {
            if (!visited1[i])
            {
                dfs(i, s, visited1, adj);
            }
        }

        // Step 2: make a transpose of the graph

        vector<int> tg[V];
        for (int i = 0; i < V; i++)
        {
            vector<int> neighbors = adj[i];
            for (int i = 0; i < neighbors.size(); i++)
            {
                tg[neighbors[i]].push_back(i);
            }
        }
        int count = 0;
        vector<bool> visited2(V, false);
        // Step 3: Do the dfs from each element of the transpose graph
        while (!s.empty())
        {
            int curr = s.top();
            s.pop();
            if (!visited2[curr])
            {
                count++;
                dfs2(curr, visited2, tg);
            }
        }

        return count;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }