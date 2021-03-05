#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Point
{
    int x;
    int y;
};

struct QueueNode
{
    Point p;
    int dist;
};

bool isValid(int row, int col, int max_rows, int max_col)
{
    return (row >= 0) && (row < max_rows) && (col >= 0) && (col < max_col);
}

int sortestPath(vector<vector<int>> &matrix, Point dest)
{
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    visited[0][0] = true;
    queue<QueueNode> q;
    q.push({{0, 0}, 0});
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};

    while (!q.empty())
    {
        QueueNode curr = q.front();
        Point curr_point = curr.p;
        if (curr_point.x == dest.x && curr_point.y == dest.y)
        {
            return curr.dist;
        }

        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int row = curr_point.x + rowNum[i];
            int col = curr_point.y + colNum[i];
            if (isValid(row, col, rows, cols) && matrix[row][col] == 1 && !visited[row][col])
            {
                visited[row][col] = true;
                QueueNode adjNode = {{row, col}, curr.dist + 1};
                q.push(adjNode);
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{

    int t = 0;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Point p;
        cin >> p.x;
        cin >> p.y;

        int len = sortestPath(matrix, p);
        cout << len << endl;
    }
    return 0;
}