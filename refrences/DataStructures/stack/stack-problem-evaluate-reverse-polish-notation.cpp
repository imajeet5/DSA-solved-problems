// Evaluate Expression

//https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Rules to solve postfix

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

int evalRPN(vector<string> &tokens)
{
    stack<int> stk;
    for (auto el : tokens)
    {
        if (el != "/" && el != "+" && el != "*" && el != "-")
        {
            int num = stoi(el);
            stk.push(num);
        }
        else
        {
            int num1 = stk.top();
            stk.pop();
            int num2 = stk.top();
            stk.pop();
            int res;

            if (el == "+")
            {
                res = num2 + num1;
            }
            else if (el == "-")
            {
                res = num2 - num1;
            }
            else if (el == "*")
            {
                res = num2 * num1;
            }
            else if (el == "/")
            {
                res = num2 / num1;
            }
            stk.push(res);
        }
    }

    return stk.top();
}

int main(int argc, char const *argv[])
{

    vector<string> nums{"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};

    int result;
    result = evalRPN(nums);

    cout << result << endl;

    return 0;
}