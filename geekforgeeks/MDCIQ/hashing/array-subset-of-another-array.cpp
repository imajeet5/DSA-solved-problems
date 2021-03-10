#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void doSomething(int arr1[], int n, int arr2[], int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }

    for (int j = 0; j < m; j++)
    {
        if (mp[arr2[j]] == 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(int argc, char const *argv[])
{

    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n >> m;
        int arr1[n], arr2[m];
        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> arr2[j];
        }

        doSomething(arr1, n, arr2, m);
    }
    return 0;
}