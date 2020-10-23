#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void stockBySell1(int arr[], int n)
{
    int minValues[n];
    minValues[0] = arr[0];
    vector<pair<int, int>> days;
    for (int i = 1; i < n; i++)
    {
        minValues[i] = min(minValues[i - 1], arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = arr[i] - minValues[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int localMin = 0, localMax = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            if (localMin != localMax)
                days.push_back(make_pair(localMin, localMax));
            localMax = i + 1;
            localMin = i + 1;
        }
        else if (arr[i + 1] >= arr[i])
        {
            localMax++;
        }
        if (arr[i + 1] == arr[i])
        {
            localMin++;
        }
    }
    if (localMax != localMin && days.size() != 0)
    {
        days.push_back(make_pair(localMin, localMax));
    }

    if (days.size() == 0)
    {
        cout << "No Profit" << endl;
        return;
    }

    for (int i = 0; i < days.size(); i++)
    {
        cout << "(" << days[i].first << "," << days[i].second << ")"
             << " ";
    }
    cout << endl;
}

int maxProfit(int arr[], int n)
{
    int maxPro = 0;
    int minPrice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPro = max(maxPro, arr[i] - minPrice);
    }

    cout << maxPro << endl;
    return maxPro;
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
        maxProfit(arr, n);
    }
    return 0;
}

/*
3
7
100 180 260 310 40 535 695
4
100 50 30 20
10
23 13 25 29 33 19 34 45 65 67
*/