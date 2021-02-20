
#include <bits/stdc++.h>

using namespace std;
#define ll long long

bool check(vector<ll>, vector<ll>, int);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> arr(n, 0), brr(n, 0);

        // increase the count of elements in first array
        for (ll i = 0; i < n; i++)
            cin >> arr[i];

        // iterate through another array
        // and decrement the count of elements
        // in the map in which frequency of elements
        // is stored for first array
        for (ll i = 0; i < n; i++)
            cin >> brr[i];

        cout << check(arr, brr, n) << "\n";
    }
    return 0;
} // } Driver Code Ends

//User function template for C++

// arr : 1st given array
// brr : 2nd given array
// n : size of both the arrays

bool check(vector<ll> arr, vector<ll> brr, int n)
{
    if (arr.size() != brr.size())
    {
        return false;
    }
    // element and count map
    unordered_map<int, int> mp_a;
    unordered_map<int, int> mp_b;

    for (int i = 0; i < n; i++)
    {
        mp_a[arr[i]]++;
        mp_b[brr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        // if count of same element in a is not equal to b
        if (mp_a[arr[i]] != mp_b[arr[i]])
        {
            return false;
        }
    }

    return true;
}