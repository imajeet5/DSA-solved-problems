// { Driver Code Starts
// C++ implementation to find the character in first
// string that is present at minimum index in second
// string
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int minIndexChar(string str, string patt)
{
    unordered_map<char, int> mp;
    int ans = -1;
    for (int i = 0; i < str.length(); i++)
    {
        // if char does not exists in map we store it.
        // basically we store the minimum index
        if (mp[str[i]] == 0)
        {
            mp[str[i]] = i + 1;
        }
    }

    for (int i = 0; i < patt.length(); i++)
    {
        if (mp[patt[i]])
        {
            if (ans == -1)
                ans = mp[patt[i]];
            else
            {
                ans = min(ans, mp[patt[i]]);
            }
        }
    }
    return ans - 1;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        string patt;
        cin >> str;
        cin >> patt;
        int ans = minIndexChar(str, patt);
        if (ans == -1)
            cout << "No character present";
        else
            cout << str[ans];
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends