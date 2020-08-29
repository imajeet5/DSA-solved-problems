// Decrement OR Increment

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

int main(int argc, char const *argv[])
{

    int n;
    cin >> n;
    if (n % 4 == 0)
        cout << ++n << endl;
    else
        cout << --n << endl;

    return 0;
}