#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// this is not the optimal solution and can be optimized further with the help of heap or using quick select.
// will do that later
void kthSmallestElement(int arr[], int n, int k)
{
    sort(arr, arr + n);
    cout << arr[k - 1] << endl;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> k;

        kthSmallestElement(arr, n, k);
    }
    return 0;
}

/*
2
6
7 10 4 3 20 15
3
5
7 10 4 20 15
4
*/