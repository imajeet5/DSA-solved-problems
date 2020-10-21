// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    void merge(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;
        int i = 0;
        int j = 0;
        // int k = 0;
        while (i < n && j <= m)
        {
            if (arr1[i] <= arr2[j])
            {
                result.push_back(arr1[i]);
                i++;
            }
            else
            {
                result.push_back(arr2[j]);
                j++;
            }
        }
        while (i < n)
        {
            result.push_back(arr1[i]);
            i++;
        }
        while (j < m)
        {
            result.push_back(arr2[j]);
            j++;
        }

        for (auto it : result)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    void merge2(int arr1[], int arr2[], int m, int n)
    {
        // the goal is to have smaller values in arr1 and larger values in arr2
        for (int i = n - 1; i >= 0; i++)
        {
            //j is pointer for arr1, we start it from the second last position
            int j = m - 2;
            int last = arr1[m - 1];
            // right sift the elements in the arr1 until the elements in the arr1 is greater then arr2[2]
            while (j >= 0 && arr1[j] > arr2[i])
            {
                arr1[j + 1] = arr1[j];
                j--;
            }
            // if there was a greater element then the current element
            // i.e. element are shifted by alteast one
            // or if the last element is greater then the current element of arr2
            if (j != m - 2 || last > arr2[i])
            {
                // insert the current element in the arr1
                arr1[j + 1] = arr2[i];
                arr2[i] = last;
            }
        }
    }
};

// { Driver Code Starts.
int main()
{
    freopen("_input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge2(arr1, arr2, n, m);
        // for (i = 0; i < n; i++)
        // {
        //     cout << arr1[i] << " ";
        // }
        // for (i = 0; i < m; i++)
        // {
        //     cout << arr2[i] << " ";
        // }
        cout << "\n";
    }
    return 0;
} // } Driver Code Ends

/*
2
4 5
1 3 5 7
0 2 6 8 9
*/