// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printDFS(int sv, vector<int> adj[], vector<bool> &visited, vector<int> &ans)
    {

        ans.push_back(sv);
        visited[sv] = true;
        //visited all the adjacent node of the current node DFS
        vector<int> neighbors = adj[sv];
        for (int i = 0; i < neighbors.size(); i++)
        {
            int currElement = adj[sv][i];
            if (!visited[currElement])
            {
                printDFS(currElement, adj, visited, ans);
            }
        }
    }

    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> visited(V, false);
        vector<int> ans;

        // printDFS(0, adj, visited);
        // this for loop is only require for the case of disconnected graphs
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                printDFS(i, adj, visited, ans);
        }

        return ans;
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
        // 2d matrix
        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

/* 
1
5
7
0 1
0 4
1 4
1 3
4 3
3 2
1 2

 */