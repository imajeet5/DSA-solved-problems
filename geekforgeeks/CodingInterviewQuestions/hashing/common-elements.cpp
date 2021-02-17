// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function Template for C++

//Back-end complete function Template for C++

vector<int> common_element(vector<int> v1, vector<int> v2)
{
    // Your code here

    vector<int> result;
    map<int, pair<int, int>> mpp;

    for (auto el : v1)
    {
        mpp[el].first++;
    }
    for (auto el : v2)
    {
        mpp[el].second++;
    }

    for (auto el : mpp)
    {
        // if element is not present if either of the two
        if (el.second.first == 0 || el.second.second == 0)
        {
            continue;
        }

        int n = min(el.second.first, el.second.second);
        for (int i = 0; i < n; i++)
        {
            result.push_back(el.first);
        }
    }

    return result;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> v1(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        int m;
        cin >> m;
        vector<int> v2(m, 0);
        for (int i = 0; i < m; i++)
        {
            cin >> v2[i];
        }
        vector<int> result;
        result = common_element(v1, v2);
        for (auto i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
} // } Driver Code Ends