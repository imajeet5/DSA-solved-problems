#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int chocolateDistribution(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int endIndex = k - 1;
    int startIndex = 0;
    int minDff = arr[endIndex] - arr[startIndex];
    endIndex++;
    startIndex++;
    while (endIndex < n)
    {
        minDff = min(minDff, arr[endIndex] - arr[startIndex]);
        endIndex++;
        startIndex++;
    }
    return minDff;
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
        int r = chocolateDistribution(arr, n, k);
        cout << r << endl;
    }
    return 0;
}

/*
2
8
3 4 1 9 56 7 9 12
5
7
7 3 2 4 9 12 56
3
*/