// for non negative number
// using bruteforce technique
#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void printSubArr(int *arr, int N, int S)
{
    int currSum;
    for (size_t i = 0; i < N; i++)
    {
        currSum = arr[i];
        for (size_t j = i + 1; j <= N; j++)
        {
            if (currSum == S)
            {
                cout << i + 1 << " " << j << endl;
                return;
            }
            if (currSum > S || j == N)
            {
                break;
            }

            currSum += arr[j];
        }
    }
    cout << -1 << endl;
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
        printSubArr(arr, N, S);
    }
    return 0;
}