#include <bits/stdc++.h>

using namespace std;

//Given an array C of size N-1 and given that there are numbers from 1 to N with one element missing, the missing number is to be found.

void missingNumbers(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i)
        {
            cout << i << endl;
            return;
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
        int N, S;
        cin >> N >> S;
        int arr[N];
        for (size_t i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        missingNumbers(arr, N);
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