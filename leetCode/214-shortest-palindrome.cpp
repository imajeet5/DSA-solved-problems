#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lps(string st)
    {
        vector<int> lps(st.size());
        int i = 1, j = 0;
        while (i < st.size())
        {
            if (st[i] == st[j])
            {
                lps[i] = j + 1;
                j++;
                i++;
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }

        return lps[lps.size() - 1];
    }

    string shortestPalindrome(string s)
    {

        string rs = s;
        reverse(rs.begin(), rs.end());
        string stDash = s + '#' + rs;
        int lp = lps(stDash);
        string sa = s.substr(lp);
        sa.reserve();
        string ans = sa + s;
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    cout << sol.shortestPalindrome("aacecaaa") << endl;
    return 0;
}