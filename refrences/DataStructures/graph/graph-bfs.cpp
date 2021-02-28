#include <bits/stdc++.h>

using namespace std;

// sv is starting vertex
void printBFS(vector<vector<int>> matrix, int sv, vector<bool> &visited)
{
    int n = matrix.size();
    // vector<bool> visited(n, false);

    queue<int> q;

    q.push(sv);
    visited[sv] = true;

    while (!q.empty())
    {
        int cv = q.front();
        q.pop();
        cout << cv << endl;
        // we will iterate through the number of edges to see check all the adjacent node of the current node
        // and push the node which is not yet visited
        for (int i = 0; i < n; i++)
        {
            if (matrix[cv][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            printBFS(matrix, i, visited);
    }
}

int main(int argc, char const *argv[])
{

    int n, e;
    cin >> n >> e;
    vector<vector<int>> matrix(n, vector<int>(n, 0));

    for (int i = 1; i <= e; i++)
    {
        int fv, sv;
        cin >> fv >> sv;
        matrix[fv][sv] = 1;
        matrix[sv][fv] = 1;
    }

    BFS(matrix);

    return 0;
}

/* 
7
7
0 1
0 2
1 5
5 4
3 4
2 3
2 6

  

 */