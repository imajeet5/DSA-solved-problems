// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// this approach is not working

//User function template for C++
class Solution
{
public:
    int countTriplet1(int arr[], int n)
    {
        // using sliding window technique
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
                    cout << "numbers are " << arr[i] << " = "
                         << arr[j] << " + " << arr[k] << endl;
                    j += 1;
                    k -= 1;

                    cT++;
                    // break;
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

    int countTriplet2(int arr[], int n)
    {
        // using frequency counting
        // compute the max value in the array
        // and create frequency array of size
        // max_val + 1.
        // We can also use HashMap to store
        // frequencies. We have used an array
        // to keep remaining code simple.
        int max_val = 0;
        for (int i = 0; i < n; i++)
            max_val = max(max_val, arr[i]);
        int freq[max_val + 1] = {0};
        for (int i = 0; i < n; i++)
            freq[arr[i]]++;

        int ans = 0; // stores the number of ways

        // Case 1: 0, 0, 0
        ans += freq[0] * (freq[0] - 1) * (freq[0] - 2) / 6;

        // Case 2: 0, x, x
        for (int i = 1; i <= max_val; i++)
            ans += freq[0] * (freq[i] * (freq[i] - 1) / 2);

        // Case 3: x, x, 2*x
        for (int i = 1; 2 * i <= max_val; i++)
            ans += (freq[i] * (freq[i] - 1) / 2 )* freq[2 * i];

        // Case 4: x, y, x + y
        // iterate through all pairs (x, y)
        for (int i = 1; i <= max_val; i++)
        {
            for (int j = i + 1; i + j <= max_val; j++)
                ans += freq[i] * freq[j] * freq[i + j];
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{

    // int arr[] = {1, 2, 3, 4, 5};
    int arr[] = {0, 1, 1, 2, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Solution ob;
    cout << ob.countTriplet2(arr, n) << "\n";

    return 0;
} // } Driver Code Ends