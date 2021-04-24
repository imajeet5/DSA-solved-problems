// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    //Function to find length of shortest common supersequence of two strings.

    int getLCSLength(string s1, string s2)
    {
        int len1 = s1.length(), len2 = s2.length();
        int dp[len1 + 1][len2 + 1] = {};
        for (int i = len1 - 1; i >= 0; i--)
        {
            for (int j = len2 - 1; j >= 0; j--)
            {
                char c1 = s1[i];
                char c2 = s2[j];
                if (c1 == c2)
                {
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }

    int shortestCommonSupersequence(char *X, char *Y, int m, int n)
    {
        string s1 = "", s2 = "";
        for (int i = 0; i < m; i++)
        {
            s1 += X[i];
        }
        for (int i = 0; i < n; i++)
        {
            s2 += Y[i];
        }
        int lcsLength = getLCSLength(s1, s2);
        return (s1.length() + s2.length() - lcsLength);
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    char X[10001], Y[10001];

    //taking total testcases
    cin >> t;
    while (t--)
    {

        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;
    }
    return 0;
}

// } Driver Code Ends