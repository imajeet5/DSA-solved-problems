#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        // this stack will store the word in reverse order
        stack<string> stk;

        string temp = "";
        string ans = "";

        // we will take each word and push it in the stack
        for (int i = 0; i < s.size(); i++)
        {
            // if we get a space then we will push the string into stack
            // only if string exist in the temp
            if (s[i] == ' ')
            {
                if (temp.size() > 0)
                {
                    stk.push(temp);
                }
                // we will empty the temp
                temp = "";
            }
            else
            {
                // we will add the element in the temp string
                temp += s[i];
            }
        }

        // when we get to the end temp will have the last string, which may also be a blank space
        ans += temp;
        // now we will pop elements from the stack and add to answer
        while (!stk.empty())
        {
            string curr = stk.top();
            ans += " " + curr;
            stk.pop();
        }

        return ans[0] == ' ' ? ans.substr(1) : ans;
    }
};