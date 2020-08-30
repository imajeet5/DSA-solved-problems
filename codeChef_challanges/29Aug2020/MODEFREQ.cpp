#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int A[N], freq[N];
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }
        int f = 0;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++)
        {
            // if the number alread been checked
            if (visited[i])
            {
                continue;
            }
            // if it is a new number, means it exist aleast once
            int counter = 1;
            for (int j = i + 1; j < N; j++)
            {
                if (A[i] == A[j])
                {
                    visited[j] = true;
                    counter++;
                }
            }
            freq[f] = counter;
            f++;
        }

        sort(freq, freq + f);
        int max_ct = INT_MIN, result;
        for (int i = 0; i < f; i++)
        {
            int ct = count(freq, freq + f, freq[i]);
            if (ct > max_ct)
            {
                max_ct = ct;
                result = freq[i];
            }
        }
        cout << result << endl;
    }
    return 0;
}