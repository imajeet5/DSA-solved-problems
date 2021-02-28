#include <bits/stdc++.h>

using namespace std;

// sv is starting vertex
void printDFS(vector<vector<int>> v, int sv, vector<bool> &visited)
{
    cout << sv << endl;
    visited[sv] = true;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[sv][i] == 1 && visited[i] == false)
        {
            printDFS(v, i, visited);
        }
    }
}

// this print entire Graph, connected or disconnected
void DFS(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<bool> visited(n, false);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printDFS(matrix, i, visited);
        }
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

    vector<bool> visited(n, false);
    printDFS(matrix, 0, visited);

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