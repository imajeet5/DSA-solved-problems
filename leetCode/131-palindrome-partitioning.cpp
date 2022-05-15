#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int begin, int end, string s)
    {
        while (begin < end)
        {
            if (s[begin++] != s[end--])
            {
                return false;
            }
        }

        return true;
    }

    void getPalindromicPartitions(int begin, vector<string> path, string s, vector<vector<string>> &result)
    {

        // the base case
        // when the begin will reach the end of the string
        if (begin == s.size())
        {
            result.push_back(path);
            return;
        }

        for (int i = begin; i < s.size(); i++)
        {
            // in the loop we will check for all the palindrom
            // from begin to ith palce
            // whenever we get a plaindromic string we will add it to our
            // recursive path and do the same thing on remaining of string

                 path.push_back(s.substr(begin, i - begin + 1));
               
                getPalindromicPartitions(i + 1, path, s, result);
              
                path.pop_back();


            // if (isPalindrome(begin, i, s))
            // {
            //     // we will add this string to our current path
            //     // as substr take number of character from the
            //     // beginning we take i-begin+1
            //     path.push_back(s.substr(begin, i - begin + 1));
            //     // now do the same stuff of rest of the string
            //     getPalindromicPartitions(i + 1, path, s, result);
            //     // now when we are backtracking, we will pop out the
            //     //  current element as it's path has been explored
            //     //  and we will try of get the next palindrom and explore
            //     //  it's path
            //     path.pop_back();
            // }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> result;
        vector<string> path;
        getPalindromicPartitions(0, path, s, result);
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string str = "aba";
    auto result = sol.partition(str);
    cout << "Done" << endl;
    return 0;
}