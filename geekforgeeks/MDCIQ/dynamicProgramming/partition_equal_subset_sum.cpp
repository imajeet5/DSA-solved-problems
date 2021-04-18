// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int equalPartition(int N, int arr[])
    {
        // first we check if the sum is not odd
        int sum = 0;
        for (int i = 0; i < N; i++)
        {
            sum += arr[i];
        }

        if (sum & 1)
        {
            return false;
        }

        // when the sum is even
        // if there is a subset exist with the target sum = sum /2 the we will return true
        int target = sum / 2;
        int dp[N + 1][target + 1] = {};
        // vector<vector<int>> dp(N + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= N; i++)
        {
            for (int j = 0; j <= target; j++)
            {
                // case 1 when i==0 and j == 0 means target sum is 0 and array length is 0
                if (i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else if (i == 0)
                {
                    // array is empty then none of the target sum is possible
                    dp[i][j] = 0;
                }
                else if (j == 0)
                {
                    // when the target sum is 0 then it is possible for all
                    dp[i][j] = 1;
                }
                else
                {
                    // this means if without including the current element in the subset
                    // target sum can be achieved then we will mark current sum as true
                    if (dp[i - 1][j] == true)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        // for rest of the cases
                        // get the current val, index of array in one less then i
                        int val = arr[i - 1];
                        // this value should be atleast greater then the current target sum
                        // rest of the element should able to make the target sum excluding current val
                        if (j >= val && dp[i - 1][j - val])
                        {
                            dp[i][j] = 1;
                        }
                    }
                }
            }
        }

        return dp[N][target];
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
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
} // } Driver Code Ends

/* 
1
5
2 4 11 10 5
 */