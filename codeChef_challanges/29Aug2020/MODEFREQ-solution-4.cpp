#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
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
            if (visited[i] == true)
                continue;
            int count = 1;
            for (int j = i + 1; j < N; j++)
            {
                if (A[i] == A[j])
                {
                    visited[j] = true;
                    count++;
                }
            }
            freq[f] = count;
            f++;
        }
        sort(freq, freq + f);
        int min = INT_MIN, r;
        for (int i = 0; i < f; i++)
        {
            int y = count(freq, freq + f, freq[i]);
            if (y > min)
            {
                min = y;
                r = freq[i];
            }
        }
        cout << r << endl;
    }
    return 0;
}