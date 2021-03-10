#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void spiralTraversingMatrix(int m, int n, vector<vector<int>> &arr)
{
    int sr = 0, sc = 0, er = m - 1, ec = n - 1;
    int k = 0;
    while (sr <= er && sc <= ec)
    {
        // print the start row --> sr
        for (int i = sc; i <= ec; i++)
        {
            cout << arr[sr][i] << " ";
            k++;
        }
        if(k == m*n) return;
        sr++;
        // print the end column --> ec
        for (int i = sr; i <= er; i++)
        {
            cout << arr[i][ec] << " ";
            k++;
        }
        if(k == m*n) return;
        ec--;
        // print the end row --> er
        for (int i = ec; i >= sc; i--)
        {
            cout << arr[er][i] << " ";
            k++;
        }
        if(k == m*n) return;
        er--;
        // print the start column --> sc
        for (int i = er; i >= sr; i--)
        {
            cout << arr[i][sc] << " ";
            k++;
        }
        if(k == m*n) return;
        sc++;
    //    return;
    }

    // cout << endl;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> arr(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        spiralTraversingMatrix(m, n, arr);
        cout << endl;
    }
    return 0;
}

/*
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12
*/