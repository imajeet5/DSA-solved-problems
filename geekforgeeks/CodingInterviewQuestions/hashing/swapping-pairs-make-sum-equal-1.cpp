// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{

public:
    int getSum(int arr[], int n)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    int findSwapValues(int A[], int n, int B[], int m)
    {
        int sum1 = getSum(A, n);
        int sum2 = getSum(B, m);

        int newSum1, newSum2, val1, val2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                newSum1 = sum1 - A[i] + B[j];
                newSum2 = sum2 - B[j] + A[i];
                if (newSum1 == newSum2)
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends