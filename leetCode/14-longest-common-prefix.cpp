#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        int minLen = INT_MAX;
        string ans;
        for (auto str : strs)
        {
            int n = str.size();
            minLen = min(minLen, n);
        }

        for (int i = 0; i < minLen; i++)
        {
            char curr = strs[0][i];
            bool flag = true;
            // if for all the string ith character is same
            for (auto str : strs)
            {
                if (str[i] != curr)
                {
                    // if any of the character in string not equal to the current character then
                    // we will return
                    return ans;
                }
            }
            ans += curr;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    Solution sol;

    vector<string> arr{"flower", "flow", "flight"};

    auto ans = sol.longestCommonPrefix(arr);
    cout << ans << endl;

    return 0;
}