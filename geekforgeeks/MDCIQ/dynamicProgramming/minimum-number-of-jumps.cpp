// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        // initializing all element of dp as INT_MAX

        // set the last element as 0
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int val = arr[i];
            // if val is 0 then we can't move anywhere and we will let it value as infinite
            if (val == 0)
            {
                continue;
            }
            int minSteps = dp[i + 1];
            for (int j = 2; j <= min(val, n - i); j++)
            {
                minSteps = min(minSteps, dp[i + j]);
            }
            dp[i] = minSteps + 1;
        }
        return dp[0];
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends