#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void stockBuySell1(int arr[], int n)
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

void stockBuySell2(int price[], int n)
{
    // Prices must be given for at least two days
    if (n == 1)
        return;

    // Traverse through given price array
    int i = 0;
    int j = 0;
    while (i < n - 1)
    {

        // Find Local Minima
        // Note that the limit is (n-2) as we are
        // comparing present element to the next element
        while ((i < n - 1) && (price[i + 1] <= price[i]))
            i++;

        // If we reached the end, break
        // as no further solution possible
        if (i == n - 1)
            break;

        // Store the index of minima
        int buy = i++;
        // i++;
        j++;

        // Find Local Maxima
        // Note that the limit is (n-1) as we are
        // comparing to previous element
        while ((i < n) && (price[i] >= price[i - 1]))
            i++;

        // Store the index of maxima
        int sell = i - 1;

        cout << "(" << buy << "," << sell << ")"
             << " ";
    }
    if (!j)
    {
        cout << "No Profit";
    }
    cout << endl;
}

int maxProfieOneTransaction(int arr[], int n)
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

int maxProfitMultipleTransactions(int arr[], int n)
{
    int best_without_stock = 0;
    int best_with_stock = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        best_with_stock = max(best_with_stock, best_without_stock - arr[i]);
        best_without_stock = max(best_without_stock, best_with_stock + arr[i]);
    }
    cout << best_without_stock << endl;
    return best_without_stock;
}

int maxProfitMultipleTransactions2(int arr[], int n)
{
    int profit = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            profit += arr[i] - arr[i - 1];
        }
    }
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
        stockBuySell2(arr, n);
    }
    return 0;
}

/*
5
6
7 1 5 3 6 4
7
100 180 260 310 40 535 695
5
5 4 3 2 1
4
100 50 30 20
84
886 2777 6915 7793 8335 5386 492 6649 1421 2362 27 8690 59 7763 3926 540 3426 9172 5736 5211 5368 2567 6429 5782 1530 2862 5123 4067 3135 3929 9802 4022 3058 3069 8167 1393 8456 5011 8042 6229 7373 4421 4919 3784 8537 5198 4324 8315 4370 6413 3526 6091 8980 9956 1873 6862 9170 6996 7281 2305 925 7084 6327 336 6505 846 1729 1313 5857 6124 3895 9582 545 8814 3367 5434 364 4043 3750 1087 6808 7276 7178 5788
*/