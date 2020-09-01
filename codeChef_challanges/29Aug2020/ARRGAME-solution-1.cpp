#include <bits/stdc++.h>
typedef long long int ll;
const unsigned int MOD = 1000000007;

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++)
    {
        int n;
        cin >> n;

        vector<int> v(n + 1, 1);
        bool flag = false;
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int zero_counter = 0;
        vector<int> zero_segements;
        for (int i = 0; i <= n; i++)
        {
            if (v[i] == 0)
            {
                zero_counter++;
            }
            else
            {
                if (zero_counter != 0)
                    zero_segements.push_back(zero_counter);
                // if (zero_counter % 2 == 1)
                //     flag = true;
                zero_counter = 0;
            }
        }
        sort(zero_segements.rbegin(), zero_segements.rend());
        if (zero_segements.size() == 0)
        {
            cout << "No" << endl;
        }
        else if (zero_segements.size() == 1)
        {
            if (zero_segements[0] % 2 == 0)
                cout << "No" << endl;
            else
                cout << "Yes" << endl;
        }
        else
        {
            int a = zero_segements[0], b = zero_segements[1];
            if ((a + 1) / 2 == b)
            {
                cout << "No" << endl;
            }
            else if ((a + 1) / 2 > b && a % 2 == 1)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
    return 0;
}