#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        long long count[n + 1];

        // Initialize base values. There is one way to cover 0 and 1
        // distances and two ways to cover 2 distance
        count[0] = 1;
        if (n >= 1)
            count[1] = 1;
        if (n >= 2)
            count[2] = 2;

        // Fill the count array in bottom up manner
        for (int i = 3; i <= n; i++)
            count[i] = (count[i - 1] + count[i - 2] + count[i - 3]) % 1000000007;

        return count[n];
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
        //taking number of steps in stair
        int n;
        cin >> n;
        Solution ob;
        //calling function countWays()
        cout << ob.countWays(n) << endl;
    }

    return 0;
}
// } Driver Code Ends