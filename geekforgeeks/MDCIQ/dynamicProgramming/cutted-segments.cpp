// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // int dp[4][n+1] = {};
        vector<vector<int>> dp(4, vector<int>(n + 1, 0));
        int arr[] = {0, x, y, z};
        // sort(arr, arr + 4);
        for (int i = 1; i < 4; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j < arr[i])
                {
                    // copy the previous row element
                    // bcz this element can't be include so we take result without it
                    dp[i][j] = dp[i - 1][j];
                }
                else if (j == arr[i])
                {
                    // in this case single piece will cover the whole rod and not need to cut
                    // but we will check if without including the element we can get greater result
                    if (dp[i - 1][j] > 0)
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    // the case when j > arr[i]
                    int rem = j - arr[i];
                    if (dp[i][rem] > 0)
                    {
                        dp[i][j] = max(dp[i][rem] + 1, dp[i - 1][j]);
                    }
                    else
                    {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }
        }

        return dp[3][n];
    }
};

// { Driver Code Starts.
int main()
{

    //taking testcases
    int t;
    cin >> t;
    while (t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        //taking types of segments
        int x, y, z;
        cin >> x >> y >> z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout << obj.maximizeTheCuts(n, x, y, z) << endl;
    }

    return 0;
} // } Driver Code Ends
  /* 
1
4
2 1 1
 */