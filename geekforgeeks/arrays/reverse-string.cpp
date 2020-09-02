#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {

        string str;
        getline(cin >> ws, str);
        for (auto it = str.rbegin(); it != str.rend(); it++)
        {
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}