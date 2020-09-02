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
        int n, k;
        cin >> n >> k;
        vector<int> values(n);
        for (int i = 0; i < n; i++)
        {
            cin >> values.at(i);
        }

        sort(values.begin(), values.end());
        for (int i = values.size() - 1; i > values.size() -1 - k; i--)
        {
            cout << values.at(i) << " ";
        }
        cout << endl;
    }
    return 0;
}