#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string removeOuterParentheses(string S)
    {
        int open = 0, close = 0, j = 0, n = S.size();
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (S[i] == '(')
                open++;
            if (S[i] == ')')
                close++;
            if (open == close)
            {
                ans += S.substr(j + 1, i - 1);
                j = i + 1;
                open = 0;
                close = 0;
            }
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution foo;
    string ans = foo.removeOuterParentheses("(()())(())");
    cout << "Result is: " << ans << endl;
    return 0;
}