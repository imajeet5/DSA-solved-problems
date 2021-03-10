// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    string UncommonChars(string str1, string str2)
    {
        const int MAX_CHAR = 26;
        string ans = "";
        int present[MAX_CHAR];
        for (int i = 0; i < MAX_CHAR; i++)
            present[i] = 0;

        int l1 = str1.size();
        int l2 = str2.size();

        for (int i = 0; i < l1; i++)
            present[str1[i] - 'a'] = 1;

        for (int i = 0; i < str2.size(); i++)
        {
            // if already present in A or for repeating character for which -1 is already set
            if (present[str2[i] - 'a'] == 1 || present[str2[i] - 'a'] == -1)
            {
                present[str2[i] - 'a'] = -1;
            }
            else
            {
                //if only present in B then
                present[str2[i] - 'a'] = 2;
            }
        }

        for (int i = 0; i < MAX_CHAR; i++)
        {
            if (present[i] == 1 || present[i] == 2)
            {
                ans += (char(i + 'a'));
            }
        }
        return ans == "" ? "-1" : ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A, B;
        cin >> A;
        cin >> B;
        Solution ob;
        cout << ob.UncommonChars(A, B);
        cout << endl;
    }
    return 0;
} // } Driver Code Ends