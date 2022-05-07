#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    double dfs(string src, string dest, unordered_map<string, bool> visited, unordered_map<string, vector<pair<string, double>>> &graph)
    {

        if (src == dest)
        {
            return 1.0;
        }

        visited[src] = true;

        for (auto child : graph[src])
        {
            if (!visited[child.first])
            {
                // we will get into the recursion stack using dfs
                double ans = dfs(child.first, dest, visited, graph);
                // at the time of backtracking
                // there will be two case here
                // 1) if we have reach the end of the path but not able to reach the destination node in which case -1 is return
                // 2) if we have reach the end where source and dest meet in that case 1 is return and at the time of backtracking we will make products of all the value we have encountered in the path
                if (ans != -1.0)
                {
                    return ans * child.second;
                }
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        // so values are stored as
        // 'a':[{'b', 2}]
        // 'b':[{'c', 3}]
        unordered_map<string, vector<pair<string, double>>> graph;

        // now we will build the graph
        for (int i = 0; i < values.size(); i++)
        {
            string src = equations[i][0];
            string dest = equations[i][1];
            graph[src].push_back({dest, values[i]});
            graph[dest].push_back({src, 1 / values[i]});
        }

        vector<double> result(queries.size());

        for (int i = 0; i < queries.size(); i++)
        {
            // if any of the source or destination is not present in the
            string src = queries[i][0];
            string dest = queries[i][1];
            // if source or destination node does not exist in the graph we will retrun -1 for this
            if (!graph.count(src) || !graph.count(dest))
            {
                result[i] = -1.0;
            }
            else
            {
                unordered_map<string, bool> visited;
                result[i] = dfs(src, dest, visited, graph);
            }
        }

        return result;
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