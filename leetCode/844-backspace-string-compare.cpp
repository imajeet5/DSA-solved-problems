#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    stack<char> getStringAsStack(string str)
    {
        stack<char> stk;

        for (auto c : str)
        {
            if (c == '#')
            {
                if (!stk.empty())
                {
                    stk.pop();
                }
            }
            else
            {
                stk.push(c);
            }
        }

        return stk;
    }

    bool backspaceCompare(string s, string t)
    {

        stack<char> ss = getStringAsStack(s);
        stack<char> ts = getStringAsStack(t);

               if (ss.size() != ts.size())
        {
            return false;
        }

        while (!ss.empty())
        {
            if (ss.top() != ts.top())
            {
                return false;
            }
            ss.pop();
            ts.pop();
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution sol;
    string s = "xywrrmp";
    string t = "xywrrmu#p";

    bool result = sol.backspaceCompare(s, t);

    cout << "Result is: " << result;

    return 0;
}