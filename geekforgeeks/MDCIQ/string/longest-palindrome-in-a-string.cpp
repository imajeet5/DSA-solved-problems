// A C++ dynamic programming
// solution for longest palindrome

#include <bits/stdc++.h>
using namespace std;

void printdp(vector<vector<bool>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        auto col = dp[i];
        for (int j = 0; j < col.size(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void printSubString(string str, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << str[i];
    }
}

bool isPalindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// using brute force approach
void longestPalindrome1(string &str)
{

    int n = str.length();
    int mx_len = 0;
    string best_s = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int len = j - i + 1;
            string substr = str.substr(i, len);
            if (isPalindrome(substr) && len > mx_len)
            {
                mx_len = len;
                best_s = substr;
            }
        }
    }
    cout << best_s;
}

// using dynamic programming
void longestPalindrome2(string &str)
{
    int n = str.length();
    int s = 0;
    int e = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {

            dp[i][i + 1] = 1;
            s = i;
            e = i + 1;
        }
    }
    // first loop is for the gap which is initially 2 and goes on increasing
    for (int i = 2; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if ((str[j] == str[j + i]) && dp[j + 1][j + i - 1])
            {
                dp[j][j + i] = 1;
                if (i > (e - s))
                {
                    s = j;
                    e = j + i;
                }
            }
        }
    }
    printdp(dp);
    printSubString(str, s, e);
    cout << endl;
}

// Driver Code
int main()
{
    string str = "forgeeksskeegfor";
    longestPalindrome1(str);
    return 0;
}
