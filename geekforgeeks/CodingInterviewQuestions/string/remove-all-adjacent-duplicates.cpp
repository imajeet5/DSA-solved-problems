#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

//for MISSISSIPIE 
//output should be mpie and I am getting mipie

string removeAdjacentDuplicates(string &s)
{
    stack<char> charStk;
    char last_removed = ' ';
    for (auto it : s)
    {
        if (charStk.empty())
        {
            last_removed = ' ';
            charStk.push(it);
            continue;
        }
        if (charStk.top() == it)
        {
            last_removed = it;
            charStk.pop();
            continue;
        }
        if (last_removed != it)
        {
            last_removed = ' ';
            charStk.push(it);
        }
    }
    string ans = "";

    while (!charStk.empty())
    {
        // if (last_removed == charStk.top())
        // {
        //     charStk.pop();
        // }
        // else
        // {
        ans += charStk.top();
        charStk.pop();
        // }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "mississipie";
    string ans = removeAdjacentDuplicates(s);
    cout << ans << endl;
    return 0;
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string ans = removeAdjacentDuplicates(s);
        cout << ans << endl;
    }
    return 0;
}

/*
2
geeksforgeek
acaaabbbacdddd
*/