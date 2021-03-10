#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void leftRightGreater(int arr[], int n)
{
    int leftMax[n];
    leftMax[0] = arr[0];
    int rightMin[n];
    rightMin[n - 1] = arr[n - 1];
    for (int i = 1; i < n; i++)
        leftMax[i] = max(leftMax[i - 1], arr[i - 1]);

    for (int i = n - 2; i >= 0; i--)
        rightMin[i] = min(rightMin[i + 1], arr[i + 1]);

    bool found = false;
    for (int i = 1; i < n - 1; i++)
    {
        if (leftMax[i] <= arr[i] && rightMin[i] >= arr[i])
        {
            cout << arr[i];
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << -1;
    }
    cout << endl;
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
        leftRightGreater(arr, n);
    }
    return 0;
}

/*
3
4
4 2 5 7
3
11 9 12
6
4 3 2 7 8 9

*/