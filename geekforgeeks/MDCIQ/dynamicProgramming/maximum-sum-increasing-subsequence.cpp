// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int maxSumIS(int arr[], int n)
    {
        // Your code goes here
        int dp[n] = {};

        int totalSum = 0;
        for (int i = 0; i < n; i++)
        {
            int maxSum = arr[i];
            for (int j = 0; j < i; j++)
            {
                if (arr[j] < arr[i] && maxSum < arr[i] + dp[j])
                {

                    maxSum = arr[i] + dp[j];
                }
            }

            dp[i] = maxSum;
            if (totalSum < maxSum)
            {
                totalSum = maxSum;
            }
        }

        return totalSum;
    }
};

// { Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution ob;
        cout << ob.maxSumIS(a, n) << "\n";
    }
    return 0;
}

/*
1
5
1 101 2 3 100
 
 */