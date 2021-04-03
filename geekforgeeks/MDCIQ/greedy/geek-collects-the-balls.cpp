// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxBalls(int N, int M, int a[], int b[])
    {
        // code here
        unordered_map<int, int> mp;
        queue<int> intersection;
        for (int i = 0; i < N; i++)
        {
            mp[a[i]]++;
        };
        for (int j = 0; j < M; j++)
        { // if map has that value
            if (mp[b[j]] > 0)
            {
                intersection.push(b[j]);
            }
        }

        int sp1 = 0;
        int sp2 = 0;
        int res = 0;
        while (true)
        {
            if (intersection.empty())
            {
                int sum1 = 0;
                int sum2 = 0;
                for (int i = sp1; i < N; i++)
                {
                    sum1 += a[i];
                    sp1 = i;
                }
                for (int j = sp2; j < M; j++)
                {
                    sum2 += b[j];
                    sp2 = j;
                }

                res += max(sum1, sum2);
                return res;
            }
            else
            {
                int ip = intersection.front();
                intersection.pop();
                int sum1 = 0;
                int sum2 = 0;
                for (int i = sp1; i < N; i++)
                {
                    sum1 += a[i];
                    sp1 = i;
                    if (a[i] == ip)
                    {
                        break;
                    }
                }
                for (int j = sp2; j < M; j++)
                {
                    sum2 += b[j];
                    sp2 = j;
                    if (b[j] == ip)
                    {
                        break;
                    }
                }

                res += max(sum1, sum2);
            }
        }
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M;
        cin >> N >> M;
        int a[N], b[M];
        for (int i = 0; i < N; i++)
            cin >> a[i];
        for (int i = 0; i < M; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.maxBalls(N, M, a, b) << "\n";
    }
    return 0;
} // } Driver Code Ends