#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void trappingRain1(int arr[], int n)
{
    int water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int l_max = *max_element(arr, arr + i);
        int r_max = *max_element(arr + i + 1, arr + n);
        int minHeight = min(l_max, r_max);
        int trappedWater = (minHeight - arr[i]);
        if (trappedWater > 0)
        {
            water += trappedWater;
        }
    }
    cout << water << endl;
}

void trappingRain2(int arr[], int n)
{
    int leftMax[n];
    int rightMax[n];
    leftMax[0] = arr[0];
    rightMax[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = max(leftMax[i - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = max(arr[i], rightMax[i + 1]);
    }
    int water = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int l_max = leftMax[i];
        int r_max = rightMax[i];
        int minHeight = min(l_max, r_max);
        int trappedWater = (minHeight - arr[i]);
        if (trappedWater > 0)
        {
            water += trappedWater;
        }
    }
    cout << water << endl;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
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
        // trappingRain1(arr, n);
        trappingRain2(arr, n);
    }
    return 0;
}

/*
2
4
7 4 0 9
3
6 9 9
*/