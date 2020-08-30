//Sums in a Triangle

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

int maxSumTriangle(vector<vector<int>> a)
{

    for (int i = a.size() - 2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            a[i][j] += max(a[i + 1][j], a[i + 1][j + 1]);
        }
    }
    return a[0][0];
}

int maxSumTriangleRecursion(vector<vector<int>> *a, int i, int j)
{
    if (i > (a->size() - 1))
    {
        return 0;
    }
    int t1 = maxSumTriangleRecursion(a, i + 1, j);
    int t2 = maxSumTriangleRecursion(a, i + 1, j + 1);
    int t = max(t1, t2) + (*a)[i][j];
    return t;
}

int maxSumTriangleRecursionCached(vector<vector<int>> *a, int i, int j, vector<vector<int>> *cache)
{
    if (i > (a->size() - 1))
    {
        return 0;
    }
    if ((*cache)[i][j])
    {
        return (*cache)[i][j];
    }
    int t1 = maxSumTriangleRecursionCached(a, i + 1, j, cache);
    int t2 = maxSumTriangleRecursionCached(a, i + 1, j + 1, cache);
    int t = max(t1, t2) + (*a)[i][j];
    (*cache)[i][j] = t;
    return t;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        vector<int> columns(size, 0);
        vector<vector<int>> tringle(size, columns);
        vector<vector<int>> cacheSum(size, columns);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> tringle[i][j];
            }
        }
        cout << maxSumTriangleRecursionCached(&tringle, 0, 0, &cacheSum) << endl;
    }
    return 0;
}
