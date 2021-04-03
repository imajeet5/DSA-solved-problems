// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct val
{
    int first;
    int second;
};

int maxChainLen(struct val p[], int n);
int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        val p[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
        }

        cout << maxChainLen(p, n) << endl;
    }
    return 0;
} // } Driver Code Ends

/*
The structure to use is as follows
struct val{
	int first;
	int second;
};*/

/*You are required to complete this method*/
bool comparator(val first, val second)
{
    if (first.first < second.first)
    {

        return true;
    }
    else
    {
        return false;
    }
}

int maxChainLen(struct val p[], int n)
{
    //Your code here
    vector<int> dp(n, 0);
    // first we sort the array
    sort(p, p + n, comparator);
    int totalMax = 0;
    // the we do the longest increasing subsequence logic
    for (int i = 0; i < n; i++)
    {
        int localMax = 0;
        for (int j = 0; j < i; j++)
        {
            if (p[j].second < p[i].first && dp[j] > localMax)
            {
                localMax = dp[j];
            }
        }

        dp[i] = localMax + 1;
        totalMax = max(totalMax, dp[i]);
    }

    return totalMax;
}