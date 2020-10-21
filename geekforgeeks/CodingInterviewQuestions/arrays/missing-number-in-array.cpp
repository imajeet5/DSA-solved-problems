#include <bits/stdc++.h>

using namespace std;

//Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

void missingNumbers(int arr[], int n)
{
    sort(arr, arr + n);
    for (int i = 0; i <= n; i++)
    {
        if (arr[i] != (i + 1))
        {
            cout << i + 1 << endl;
            return;
        }
    }
}

void missingNumbers2(int arr[], int n)
{
    // For xor of all the elements in array
    int x1 = arr[0];

    // For xor of all the elements from 1 to n+1
    int x2 = 1;

    for (int i = 1; i < n; i++)
        x1 = x1 ^ arr[i];

    for (int i = 2; i <= n + 1; i++)
        x2 = x2 ^ i;

    cout << (x1 ^ x2) << endl;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N - 1];
        for (size_t i = 0; i < N - 1; i++)
        {
            cin >> arr[i];
        }
        missingNumbers2(arr, N - 1);
    }
    return 0;
}
/*
2
5
1 2 3 5
10
1 2 3 4 5 6 7 8 10
*/