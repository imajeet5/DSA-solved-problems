// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

bool isValid(string s)
{
    stack<char> stk;
    stk.push(s.at(0));
    for (int i = 1; i < s.length(); i++)
    {
        if (stk.empty())
        {
            stk.push(s.at(i));
            continue;
        }
        if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
        {
            stk.push(s.at(i));
            continue;
        }

        if (stk.top() == '(' && s.at(i) == ')')
        {
            stk.pop();
        }
        else if (stk.top() == '{' && s.at(i) == '}')
        {
            stk.pop();
        }
        else if (stk.top() == '[' && s.at(i) == ']')
        {
            stk.pop();
        }
        else
        {
            return false;
        }
    }

    if (stk.empty())
    {
        return true;
    }
    return false;
}

bool isValid2(string s)
{
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin >> ws, s);
        bool result = isValid(s);
        cout << (result ? "true" : "false") << endl;
    }
    return 0;
}