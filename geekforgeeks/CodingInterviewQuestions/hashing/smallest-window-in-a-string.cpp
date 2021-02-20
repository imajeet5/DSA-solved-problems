// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// This solution give TLE

class Solution
{
public:
    string getSubstring(string s, int start, int end)
    {
        string ans = "";
        for (int i = start; i <= end; i++)
        {
            ans += s[i];
        }
        return ans;
    }

    string smallestWindow(string s, string p)
    {
        // Your code here
        string ans = "";
        unordered_map<char, int> mp2;
        // put the characters of p in map
        for (int i = 0; i < p.length(); i++)
        {
            mp2[p[i]]++;
        }

        int char_matched = 0;
        int char_in_p = p.length();
        unordered_map<char, int> mp1;
        int i = 0, j = 0;

        while (true)
        {
            bool visited1 = false;
            bool visited2 = false;

            while (i < s.length() && char_matched < char_in_p)
            {
                mp1[s[i]]++;
                // in this condition we have found one matching character if mp2 has the character
                if (mp2[s[i]] && mp1[s[i]] <= mp2[s[i]])
                    char_matched++;

                visited1 = true;
                i++;
            }
            // when we got here all the character has been found
            // now we will remove the character to find the lowest substring for which condition holds
            while (j < i && char_matched == char_in_p)
            {
                string currStr = getSubstring(s, j, i);
                if (ans.length() == 0 || currStr.length() < ans.length())
                    ans = currStr;

                // remove the jth element from the map;
                mp1[s[j]]--;
                // the count of jth element decrease below the required count
                if (mp2[s[j]] && mp1[s[j]] < mp2[s[j]])
                    char_matched--;
                j++;
                visited2 = true;
            }

            if (!visited1 && !visited2)
                break;
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} // } Driver Code Ends