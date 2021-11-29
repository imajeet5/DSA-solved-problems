#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        // vector<vector<int>> vec( n , vector<int> (m, 0));
        // bool dp[n][n] = {0};
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int maxSubStr = 0;
        if (s.size() == 1)
        {
            return s;
        }
        string subS = s.substr(0, 1);

        // we will traverse all the diagonals
        for (int d = 0; d < n; d++)
        {
            // this for loop will traverse each diagonal one by one
            for (int row = 0, col = d; col < n; row++, col++)
            {
                // if this is 0th diagonal
                if (d == 0)
                {
                    dp[row][col] = 1;
                }
                else if (d == 1)
                {
                    dp[row][col] = s[row] == s[col];
                }

                else
                {
                    dp[row][col] = (s[row] == s[col]) && dp[row + 1][col - 1];
                }
                if (dp[row][col])
                {
                    if ((col - row) >= maxSubStr)
                    {
                        maxSubStr = col - row;
                        subS = "";
                        for (int k = row; k <= col; k++)
                        {
                            subS += s[k];
                        }
                    }
                }
            }
        }

        return subS;
    }
};

class Solution2
{
public:
    void getAllSubstring(string s, vector<string> &substrings, int i, string current)
    {

        // first we push the current substring in substrings array
        substrings.push_back(current);
        // now for every character of string we will determine the substring
        for (int j = i; j < s.size(); j++)
        {
            current += s[j];
            getAllSubstring(s, substrings, j + 1, current);
            current.pop_back();
        }
    };

    string longestPalindrome(string s)
    {
        vector<string> substrings;
        string current = "";
        getAllSubstring(s, substrings, 0, current);
        
        
        
        return "hello";
    }
};

int main(int argc, char const *argv[])
{
    Solution2 sol;
    auto ans = sol.longestPalindrome("abc");
    cout << ans << endl;

    return 0;
}