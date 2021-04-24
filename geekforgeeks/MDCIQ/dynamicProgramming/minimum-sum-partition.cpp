// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int minDiffernce(int arr[], int n)
    {
        // so we have to divide the array into two sets S1 and S2 with minimum difference btw them
        // from S1 and S2 one of them is larger and other is smaller or both are equal
        // difference is abs(SumOfArray - 2S1). So suppose S1 is smaller then S1 should be as close to SumOfArray/2 as possible
        // to make the difference lowest.
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        int targetSum = sum / 2 + 1;
        // we will check if the target sum is possible from the given elements
        bool dp[n + 1][targetSum] = {};

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < targetSum; j++)
            {
                if (j == 0)
                {
                    // for the first column, i.e. zero sum so it is possible for all elements
                    dp[i][j] = true;
                }
                else if (i == 0)
                {
                    // with empty set none of the sum is possible
                    dp[i][j] = false;
                }
                else if (arr[i - 1] > j)
                {
                    // if current element of the subset is smaller then the sum
                    // then we will just copy the previous value without the current element
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    // if the current element is greater or equal to the sum
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        }

        // now we will get the min diff
        int diff = INT_MAX;
        for (int i = 0; i < targetSum; i++)
        {
            int s1 = i;
            int s2 = sum - i;
            // we will check for the last row bcz it contain all the elements of the subset for the max target sum that exists
            if (dp[n][i] == true && diff > abs(s1 - s2))
            {
                diff = abs(s1 - s2);
            }
        }

        return diff;
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
        cout << ob.minDiffernce(a, n) << "\n";
    }
    return 0;
} // } Driver Code Ends