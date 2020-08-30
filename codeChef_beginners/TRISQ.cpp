//Fit Squares in Triangle

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

int getMaxSquares(int n)
{
    int m = n / 2;
    return m * (m - 1) / 2;
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int maxSquares = getMaxSquares(n);
        cout << maxSquares << endl;
    }
    return 0;
}