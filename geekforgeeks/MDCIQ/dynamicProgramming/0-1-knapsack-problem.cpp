// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Returns the maximum value that
    // can be put in a knapsack of capacity W
    int knapSack(int W, int wt[], int val[], int n)
    {
        // Your code here
        // vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        int dp[n + 1][W + 1] = {};
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                // check if the current element is eligible of comming into subsets
                if (wt[i - 1] <= j)
                {
                    // if it is then check if element at the remaining capacity + current weight is greater than
                    // if element is not included
                    int rCap = j - wt[i - 1];
                    if (dp[i - 1][rCap] + val[i - 1] > dp[i - 1][j])
                    {
                        dp[i][j] = dp[i - 1][rCap] + val[i - 1];
                    }
                    else
                    {
                        // just put the max of previous sub sequence
                        dp[i][j] = dp[i - 1][j];
                    }
                }
                else
                {
                    // current element is not eligible then we will put the last max
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][W];
    }
};

// { Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        //reading number of elements and weight
        int n, w;
        cin >> n >> w;

        int val[n];
        int wt[n];

        //inserting the values
        for (int i = 0; i < n; i++)
            cin >> val[i];

        //inserting the weights
        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution ob;
        //calling method knapSack()
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
} // } Driver Code Ends