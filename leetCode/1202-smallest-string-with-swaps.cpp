#include <bits/stdc++.h>

using namespace std;

class Solution2
{

public:
    void dfs(vector<vector<int>> &adjList, int x, unordered_set<int> &seen, vector<string> &sets, int seti, unordered_map<int, int> &parentSet, string &s)
    {
        if (seen.find(x) != seen.end())
            return;
        seen.insert(x);
        sets[seti].push_back(s[x]);
        parentSet[x] = seti;
        auto &children = adjList[x];
        for (auto child : children)
        {
            dfs(adjList, child, seen, sets, seti, parentSet, s);
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int n = s.length();
        vector<vector<int>> adjList(n);

        for (auto &pair : pairs)
        {
            adjList[pair[0]].push_back(pair[1]);
            adjList[pair[1]].push_back(pair[0]);
        }

        unordered_set<int> seen;
        vector<string> sets;
        unordered_map<int, int> parentSet;
        int seti = 0;

        for (int i = 0; i < n; i++)
        {
            if (seen.find(i) == seen.end())
            {
                string newSet = "";
                sets.push_back(newSet);
                dfs(adjList, i, seen, sets, seti, parentSet, s);
                seti++;
            }
        }
        int setSize = sets.size();

        vector<int> its(setSize);
        for (auto &thing : sets)
        {
            sort(thing.begin(), thing.end());
        }
        for (int i = 0; i < n; i++)
        {
            int j = parentSet[i];
            s[i] = sets[j][its[j]++];
        }

        return s;
    }
};

class Solution3
{
public:
    vector<int> indices; // Stores indices of same group.
    vector<bool> visited;
    vector<vector<int>> adjList;
    string indiceString;       // Stores  string formed by indices in the same group.
    void dfs(string &s, int n) // DFS to get all indices in same group.
    {
        visited[n] = true;
        indices.push_back(n);
        indiceString += s[n];
        for (int &i : adjList[n])
            if (!visited[i])
                dfs(s, i);
    }
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        adjList.resize(s.length());
        visited.resize(s.length(), false);
        // Build the adjacency list
        for (vector<int> edge : pairs)
        {
            int source = edge[0];
            int destination = edge[1];

            // Undirected edge
            adjList[source].push_back(destination);
            adjList[destination].push_back(source);
        }
        for (int i = 0; i < s.length(); i++)
            if (!visited[i])
            {
                indiceString = ""; // Clear string formed by one group of indices before finding next group.
                indices.clear();   // Clear indices vector before finding another group.
                dfs(s, i);
                sort(indiceString.begin(), indiceString.end()); // Sort the characters in the same group.
                sort(indices.begin(), indices.end());           // Sort the indices in the same group.
                for (int i = 0; i < indices.size(); i++)        // Replace all the indices in the same group with the sorted characters.
                    s[indices[i]] = indiceString[i];
            }
        return s;
    }
};

class Solution
{
public:
    // Maximum number of vertices

    vector<bool> visited;
    vector<vector<int>> adj;

    void DFS(string &s, int vertex, vector<char> &characters, vector<int> &indices)
    {
        // Add the character and index to the list
        characters.push_back(s[vertex]);
        indices.push_back(vertex);

        visited[vertex] = true;

        // Traverse the adjacents
        for (int adjacent : adj[vertex])
        {
            if (!visited[adjacent])
            {
                DFS(s, adjacent, characters, indices);
            }
        }
    }

    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        adj.resize(s.length());
        visited.resize(s.length(), false);
        // Build the adjacency list
        for (vector<int> edge : pairs)
        {
            int source = edge[0];
            int destination = edge[1];

            // Undirected edge
            adj[source].push_back(destination);
            adj[destination].push_back(source);
        }

        for (int vertex = 0; vertex < s.size(); vertex++)
        {
            // If not covered in the DFS yet
            if (!visited[vertex])
            {
                vector<char> characters;
                vector<int> indices;

                DFS(s, vertex, characters, indices);
                // Sort the list of characters and indices
                sort(characters.begin(), characters.end());
                sort(indices.begin(), indices.end());

                // Store the sorted characters corresponding to the index
                for (int index = 0; index < characters.size(); index++)
                {
                    s[indices[index]] = characters[index];
                }
            }
        }

        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    vector<vector<int>> pairs = {{0, 3}, {1, 2}, {0, 2}};
    string s = "dacb";
    string result = sol.smallestStringWithSwaps(s, pairs);
    cout << result << endl;

    return 0;
}