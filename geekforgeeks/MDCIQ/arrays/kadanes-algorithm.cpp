#include <bits/stdc++.h>
using namespace std;

void printMaxSum(int arr[], int N)
{
    int meh = 0;
    int msf = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        meh += arr[i];
        msf = max(meh, msf);
        meh = max(meh, 0);
    }
    cout << msf << endl;
}

void printMaxSum2(int arr[], int N)
{
    // msf -> maximum so far
    // meh -> maximum ending here
    int msf = INT_MIN, meh = 0;
    for (int i = 0; i < N; i++)
    {
        meh = meh + arr[i];
        meh = max(arr[i], meh);
        msf = max(msf, meh);
    }

    cout << msf << endl;
}

int main()
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (size_t i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        printMaxSum(arr, N);
    }
    return 0;
}

/*
1
9
-2,1,-3,4,-1,2,1,-5,4
*/