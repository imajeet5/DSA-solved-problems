#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> arr(n);
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        int result = 1;

     
        map<int, int> mp2;

        for (auto a : mp)
        {
            mp2[a.second]++;
        }

        for (auto a : mp2)
        {
            if (a.second > maxi)
            {
                maxi = a.second;
                result = a.first;
            }
        }

        cout << result << "\n";
    }
    return 0;
}
