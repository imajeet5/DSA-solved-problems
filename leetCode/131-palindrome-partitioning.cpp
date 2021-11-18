#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s, int begin, int end)
    {
        while (begin < end)
        {
            if (s[begin++] != s[end--])
            {
                return false;
            }
            return true;
        }

        return false;
    }

    void getPalindromicPartition(int begin, vector<string> current, string s, vector<vector<string>> &result)
    {

        // base case
        // begin reaches the end of the string
        if (begin == s.size())
        {
            // then we will push the current array in result
            result.push_back(current);
            return;
        }

        for (int i = begin; i < s.size(); i++)
        {
            // we will check if the staring is palindrom from begin to i
            if (isPalindrome(s, begin, i))
            {
                // if the current sub string is palindrom then only we will move forward with
                // the recursion
                // we will insert it the current array and check for all the partion in the remaining string
                current.push_back(s.substr(begin, i + 1));
                // now for the reaming part of the string we will check for all the palindrom
                getPalindromicPartition(i + 1, current, s, result);
                // at the time of backtracking we will remove the last element that has been added
                // as it has already been part of the palindromic string
                current.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> current;
        getPalindromicPartition(0, current, s, result);
        return result;
    }
};