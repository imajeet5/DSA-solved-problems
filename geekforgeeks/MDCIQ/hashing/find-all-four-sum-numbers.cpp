// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int k);

// Position this line where user code will be pasted.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<vector<int>> ans = fourSum(a, k);
        for (auto &v : ans)
        {
            for (int &u : v)
            {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty())
        {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends

// User function template for C++

// arr[] : int input array of integers
// k : the quadruple sum required
vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    vector<vector<int>> res;
    if (arr.empty())
    {
        return res;
    }
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int remaining = k - arr[i] - arr[j];

            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                int twoSum = arr[left] + arr[right];
                if (twoSum < remaining)
                    left++;
                else if (twoSum > remaining)
                    right--;
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = arr[i];
                    quadruplet[1] = arr[j];
                    quadruplet[2] = arr[left];
                    quadruplet[3] = arr[right];
                    res.push_back(quadruplet);

                    while (left < right && arr[left] == quadruplet[2])
                        ++left;
                    while (left < right && arr[right] == quadruplet[3])
                        --right;
                }
            }

            while (j + 1 < n && arr[j + 1] == arr[j])
                ++j;
        }

        while (i + 1 < n && arr[i + 1] == arr[i])
            ++i;
    }

    return res;
}