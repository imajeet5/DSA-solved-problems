// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    cout << endl;
    vector<int> ans;
    int l = k - 1;
    int mx = *max(arr, arr + l);
    ans.push_back(mx);
    for (int i = l + 1; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx = arr[i];
            ans.push_back(mx);
        }
        else
        {
            ans.push_back(mx);
        }
    }

    return ans;
}

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;

    while (t--)
    {

        int n, k;
        cin >> n >> k;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<int> res = max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
} // } Driver Code Ends

/*
1
9 3
1 2 3 1 4 5 2 3 6

*/