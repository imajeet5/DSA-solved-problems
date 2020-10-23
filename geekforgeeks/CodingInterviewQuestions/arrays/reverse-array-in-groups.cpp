#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

void reverseInGroup(int arr[], int n, int k)
{
    for (int i = 0; i < n; i = i + k)
    {
        int s = i;
        int e = min(i + k - 1, n - 1);
        while (s <= e)
        {
            int startValue = arr[s];
            arr[s] = arr[e];
            arr[e] = startValue;
            s++;
            e--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
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
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        };

        reverseInGroup(arr, n, k);
    }
    return 0;
}