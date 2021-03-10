// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

bool areParanthesisBalanced(string expr)
{
    stack<char> s;
    char x;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i])
        {
        case ')':

            // Store the top element in a
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }

    // Check Empty Stack
    return (s.empty());
}

// Function to return if the paranthesis are balanced or not
bool ispar(string x)
{
    // Your code here
    stack<char> stk;
    unordered_map<char, char> p;
    p.insert(make_pair('(', ')'));
    p.insert(make_pair('[', ']'));
    p.insert(make_pair('{', '}'));

    for (auto c : x)

    {
        if (stk.empty())
        {
            stk.push(c);
            continue;
        }

        if (p[stk.top()] == c)
        {
            stk.pop();
            continue;
        }
        stk.push(c);
    }

    if (stk.empty())
        return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int t;
    string a;
    cin >> t;
    while (t--)
    {
        cin >> a;
        if (ispar(a))
            cout << "balanced" << endl;
        else
            cout << "not balanced" << endl;
    }
} // } Driver Code Ends