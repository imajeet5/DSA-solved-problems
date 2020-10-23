#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int equilibriumPoint(int arr[], int n)
{
    if (n == 0 || n == 2)
    {
        return -1;
    }
    if (n == 1)
    {
        return 1;
    }

    int sumA[n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sumA[i] = sum;
    }
    int total = sumA[n - 1];

    for (int i = 1; i < n - 1; i++)
    {
        int leftSum = sumA[i] - arr[i];
        int rightSum = total - sumA[i];
        if (leftSum == rightSum)
            return i + 1;
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << equilibriumPoint(arr, n);
    return 0;

    int t = 0;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        equilibriumPoint(arr, n);
    }
    return 0;
}