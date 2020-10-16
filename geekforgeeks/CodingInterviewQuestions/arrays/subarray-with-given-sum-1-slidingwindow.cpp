// using sliding
// for non negative number
// using bruteforce technique
#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void printSubArr(int *arr, int N, int S)
{
    // starte index of the sum is 'startIndex' and end index is 'i'
    int currSum = arr[0], startIndex = 0, i;
    for (int i = 1; i <= N; i++)
    {
        // start removing the element until the currSum is greater then S and startIndex < i - 1 otherwise there will be no element left
        while (currSum > S && startIndex < i - 1)
        {
            currSum -= arr[startIndex];
            startIndex++;
        }
        if (currSum == S)
        {
            cout << startIndex + 1 << " " << i << endl;
            return;
        }

        if (i < N)
            currSum += arr[i];
    }
    cout << -1 << endl;
    return;
}

int main(int argc, char const *argv[])
{

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