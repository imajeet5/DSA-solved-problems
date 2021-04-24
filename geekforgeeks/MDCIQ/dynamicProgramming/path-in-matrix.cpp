// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int dp[N][N] = {};

        // first row will be as it is...no change
        int overallMax = 0;

        for (int j = 0; j < N; j++)
        {
            dp[0][j] = Matrix[0][j];
            overallMax = max(dp[0][j], overallMax);
        }
        // second row onwards
        for (int i = 1; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int first = 0, second = 0, third = 0;
                if (j - 1 >= 0)
                {
                    first = dp[i - 1][j - 1];
                }
                second = dp[i - 1][j];
                if (j + 1 < N)
                {
                    third = dp[i - 1][j + 1];
                }
                int maxVal = max(first, max(second, third));

                dp[i][j] = Matrix[i][j] + maxVal;

                overallMax = max(dp[i][j], overallMax);
            }
        }

        return overallMax;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for (int i = 0; i < N * N; i++)
            cin >> Matrix[(i / N)][i % N];

        Solution ob;
        cout << ob.maximumPath(N, Matrix) << "\n";
    }
    return 0;
} // } Driver Code Ends