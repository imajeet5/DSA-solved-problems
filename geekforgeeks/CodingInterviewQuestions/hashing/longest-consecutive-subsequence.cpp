// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        cout << findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
} // } Driver Code Ends

// arr[] : the input array
// N : size of the array arr[]

// return the length of the longest subsequene of consecutive integers
int findLongestConseqSubseq0(int arr[], int n)
{
    int ans = 0, count = 0;

    // sort the array
    sort(arr, arr + n);

    vector<int> v;
    v.push_back(arr[0]);

    //insert repeated elements only once in the vector
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    // find the maximum length
    // by traversing the array
    for (int i = 0; i < v.size(); i++)
    {

        // Check if the current element is equal
        // to previous element +1
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        // reset the count
        else
            count = 1;

        // update the maximum
        ans = max(ans, count);
    }
    return ans;
}
int findLongestConseqSubseq(int arr[], int N)
{
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        s.insert(arr[i]);
    }

    int prev = *s.begin();
    int len = 1;
    int max_len = 1;
    int isFirst = 1;
    for (auto val : s)
    {
        if (isFirst)
        {
            isFirst = 0;
            continue;
        }

        if (val == prev + 1)
        {
            len++;
        }
        else
        {
            len = 1;
        }
        prev = val;
        max_len = max(len, max_len);
    }
    return max_len;
}