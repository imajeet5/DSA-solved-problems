#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

// brute force O(n^2)
void leaders1(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool isleader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                isleader = false;
                break;
            }
        }
        if (isleader)
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

// optimized O(n)
void leaders2(int arr[], int n)
{
    int mx = arr[n - 1];
    stack<int> leaders;
    leaders.push(mx);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= mx)
        {
            mx = arr[i];
            leaders.push(mx);
        }
    }

    while (leaders.size())
    {
        cout << leaders.top() << " ";
        leaders.pop();
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);
    int arr[] = {7, 4, 5, 7, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    leaders2(arr, n);
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
        leaders2(arr, n);
    }
    return 0;
}



/*
3
6
16 17 4 3 5 2
5
1 2 3 4 0
5
7 4 5 7 3
*/