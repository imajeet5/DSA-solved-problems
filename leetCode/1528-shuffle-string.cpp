#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        vector<char> ans_arr(s.size(), '\0');
        string ans_str;
        for (int i = 0; i < indices.size(); i++)
        {
            ans_arr[indices[i]] = s[i];
        }
        for (int i = 0; i < ans_arr.size(); i++)
        {
            ans_str += ans_arr[i];
        }

        return ans_str;
    }
};
