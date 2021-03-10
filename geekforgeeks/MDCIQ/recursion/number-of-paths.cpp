// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



int getNumPaths(int m, int n, int r, int c) {
    // if both are equal then we are at the correct node
    if (r == m && c == n) {

        return 1;
    }

    // if one of them is greater then we go no further just return 
    if (r > m || c > n) {
        return 0;
    }

    // visit right
    return getNumPaths(m, n, r + 1, c) + getNumPaths(m, n, r, c + 1);


}

long long  numberOfPaths(int m, int n) {
    return  getNumPaths(m, n, 1, 1);

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