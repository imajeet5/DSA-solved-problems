#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void rotate(int arr[], int r, int n)
{

    r = r % n;
    int temp1[r];
    int res[n];
    for (int i = 0; i < r; i++)
    {
        temp1[i] = arr[i];
    }
    for (int i = 0, j = 0; i < n; i++)
    {
        if (i < n - r)
        {
            res[i] = arr[i + r];
        }
        else
        {
            res[i] = temp1[j];
            j++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
// #ifndef ONLINE_JUDGE
//     freopen("_input.txt", "r", stdin);
//     freopen("_output.txt", "w", stdout);
// #endif
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int r = 10;
        // cin >> r;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        rotate(arr, r, n);
    }
    return 0;
}
