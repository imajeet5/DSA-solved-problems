// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<int> countDistinct(int[], int, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        vector<int> result = countDistinct(a, n, k);
        for (int i : result)
            cout << i << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends

vector<int> countDistinct(int A[], int n, int k)
{
    vector<int> results;
    int distinct = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < k; i++)
    {
        if (mp[A[i]] == 0)
        {
            distinct++;
        }
        mp[A[i]] +=1;
    }

    results.push_back(distinct);

    for (int i = k; i < n; i++)
    {

        if (mp[A[i - k]] == 1)
            distinct--;

        mp[A[i - k]] -=1;

        if (mp[A[k]] == 0)
            distinct++;

        mp[A[k]]+=1;

        results.push_back(distinct);
    }
    return results;
}
/* 
1
7 4
1 2 1 3 4 2 3
 */