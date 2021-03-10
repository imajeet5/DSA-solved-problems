// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

int countPathDpRecursion(int m, int n, int r, int c, vector<vector<int>>& dp) {
    // if both are equal then we are at the correct node
    if (r == m && c == n) {

        return 1;
    }

    // if one of them is greater then we go no further just return 
    if (r > m || c > n) {
        return 0;
    }

    if (dp[r][c] != -1) {
        return dp[r][c];
    }
    dp[r][c] = countPathDpRecursion(m, n, r + 1, c, dp) + countPathDpRecursion(m, n, r, c + 1, dp);
    return dp[r][c];
}

int countPathsCombintions(int m, int n) {
    // here we will find the m+n-2
    //                            C
    //                              m-1 or n-1
    // of the the step that we need to take .i.e m+n-2 we only need to choose m-1 or n-1
    int N = m + n - 2; // total number of steps
    int r = m - 1; // steps that need to be choose
    double result = 1;

    // Calculate nCr
    // 10C3 = (8*9*10)/(3*2*1);

    for (int i = 1; i <= r; i++) {
        result *= (N - r + 1) / i;
    }

    return (int)result;


}

int countPathIterativeDP(int n, int m) {
    int T[n][m];
    for (int i = 0; i < n; i++) {
        T[i][0] = 1;
    }

    for (int i = 0; i < m; i++) {
        T[0][i] = 1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            // time taken is the sum of time taken to reach time top and left side of the current cell
            T[i][j] = T[i - 1][j] + T[i][j - 1];
        }
    }
    return T[n - 1][m - 1];
}


long long  numberOfPaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPathDpRecursion(m - 1, n - 1, 0, 0, dp);

}

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        cout << numberOfPaths(m, n) << endl;
    }
    return 0;
}  // } Driver Code Ends

/*
1
3 3


1
5 1

 */