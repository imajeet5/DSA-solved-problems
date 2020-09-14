#include <bits/stdc++.h>

using namespace std;

string removeDuplicatesWithoutStack(string S)
{

    string mod = "";
    int i = 0;
    for (char c : S)
    {
        // cout<<"mod[ "<< i<< "]= "<< mod[i]  << "  c ="<< c<<endl;
        if (mod.length() == 0)
        {
            mod += c;
        }
        else if (mod[i] != c)
        {
            mod += c;
            i++;
        }
        else
        {
            // cout<<"mod = " << mod<<endl;
            mod.erase(i, 1);
            i--;
            if (mod.length() == 0)
                cout << "empty .. ";
            if (i < 0)
            {
                i = 0;
            }
        }
    }
}

string removeDuplicatesUsingPointer(string S)
{
    int stptr = -1;
    for (auto c : S)
    {

        if (stptr == -1)
        {
            stptr++;
            S.at(stptr) = c;
            continue;
        }
        char existing = S.at(stptr);
        if (c == existing)
        {
            stptr--;
        }
        else
        {
            stptr++;
            S.at(stptr) = c;
        }
    }
    string ans = "";
    for (int i = 0; i <= stptr; i++)
    {
        ans.push_back(S.at(i));
    }
    return ans;
}

string removeDuplicates(string S)
{
    stack<char> stk;
    for (auto c : S)
    {
        if (stk.empty())
        {
            stk.push(c);
            continue;
        }
        char existing = stk.top();
        if (existing == c)
        {
            stk.pop();
        }
        else
        {
            stk.push(c);
        }
    }

    S.clear();
    while (!stk.empty())
    {
        S.push_back(stk.top());
        stk.pop();
    }
    reverse(S.begin(), S.end());
    return S;
}

int main(int argc, char const *argv[])
{
    string str = "abbaca";
    string result = removeDuplicatesUsingPointer(str);
    cout << result << endl;
    return 0;
}