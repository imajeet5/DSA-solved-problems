// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> allPairs(int a[], int b[], int n, int m, int k);

int main()
{
    long long t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int a[n], b[m];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        vector<pair<int, int>> vp = allPairs(a, b, n, m, k);
        int sz = vp.size();
        if (sz == 0)
            cout << -1 << endl;
        else
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == 0)
                    cout << vp[i].first << " " << vp[i].second;
                else
                    cout << ", " << vp[i].first << " " << vp[i].second;
            }
            cout << endl;
        }
    }
    return 0;
} // } Driver Code Ends

vector<pair<int, int>> allPairs(int a[], int b[], int n, int m, int k)
{
    // Your code goes here

    vector<pair<int, int>> ans;
    unordered_map<int, int> mp_a;
    unordered_map<int, int> mp_b;

    for (int i = 0; i < n; i++)
    {
        mp_a[a[i]] = k - a[i];
    }
    for (int i = 0; i < m; i++)
    {
        mp_b[b[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        // if map b has complementry value
        if (mp_b[mp_a[a[i]]] != 0)
        {
            ans.push_back(make_pair(a[i], mp_a[a[i]]));
        }
    }

    return ans;
}