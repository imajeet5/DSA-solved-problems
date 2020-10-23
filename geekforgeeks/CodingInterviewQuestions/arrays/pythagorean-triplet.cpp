// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends

//User function template for C++
class Solution
{
public:
    int countTriplet(int arr[], int n)
    {
        // sort the array
        sort(arr, arr + n);
        int cT = 0;

        // for every element in arr
        // check if a pair exist(in array) whose
        // sum is equal to arr element
        for (int i = n - 1; i >= 0; i--)
        {
            int j = 0;
            int k = i - 1;

            // Iterate forward and backward to find
            // the other two elements
            while (j < k)
            {

                // If the two elements sum is
                // equal to the third element
                if (arr[i] == arr[j] + arr[k])
                {

                    // pair found
                    // cout << "numbers are " << arr[i] << " "
                    //      << arr[j] << " " << arr[k] << endl;
                    cT++;
                    j += 1;
                    k -= 1;
                    // return;
                }

                // If the element is greater than
                // sum of both the elements, then try
                // adding a smaller number to reach the
                // equality
                else if (arr[i] > arr[j] + arr[k])
                    j += 1;

                // If the element is smaller, then
                // try with a smaller number
                // to reach equality, so decrease K
                else
                    k -= 1;
            }
        }

        // No such triplet is found in array
        // cout << "No such triplet exists";
        return cT;
    }

    // Function to check if the
    // Pythagorean triplet exists or not
    bool checkTriplet(int arr[], int n)
    {
        int sqArr[n];
        for (int i = 0; i < n; i++)
        {
            sqArr[i] = arr[i] * arr[i];
        }
        int triplets = countTriplet(sqArr, n);
        if (triplets > 0)
            return true;
        else
            return false;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.checkTriplet(arr, n);
        if (ans)
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}
// } Driver Code Ends