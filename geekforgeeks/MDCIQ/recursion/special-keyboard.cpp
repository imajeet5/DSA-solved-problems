// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


// User function Template for C++

class Solution {
public:
    unsigned long long int findOptimal2(int N) {
        if (N <= 6) {
            return N;
        }
        // I have take one addition for taking index from 1
        int results[N + 1] = { 0 };
        // initializing 1 to 6 to the values
        for (int i = 1; i <= 6; i++) {
            results[i] = i;
        }

        // we start from 7 and calculate result for each number
        for (int i = 7; i <= N; i++) {
            for (int j = i - 3; j >= 1; j--) {
                int curr = (N - j - 1) * results[j - 1];
                if (curr > results[i]) {
                    results[i] = curr;
                }
            }
        }

        return results[N];
    }

    unsigned long long int findOptimal(int N, int results[]) {
        if (N <= 6) {
            return N;
        }

        if (results[N] != 0) {
            return results[N];
        }
        int mx = 0;

        for (int i = N - 3; i >= 1; i--) {
            int curr = (N - i - 1) * findOptimal(i, results);
            if (curr > mx) {
                mx = curr;
            }
        }
        results[N] = mx;
        return mx;
    }

    unsigned long long int optimalKeys(int N) {
        int results[100] = { 0 };
        return findOptimal(N, results);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.optimalKeys(N) << "\n";
    }
    return 0;
}  // } Driver Code Ends